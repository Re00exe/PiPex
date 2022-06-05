/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:14:47 by midfath           #+#    #+#             */
/*   Updated: 2022/06/05 18:52:25 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

void	ft_exe(t_list *node, t_pip *p)
{
	if (node->next && p->input == -1)
		p->err_f = 1;
	else if (!node->next && p->output == -1)
		p->err_f = 1;
}

void	*ft_child_process(t_pip *p, int f[2], t_list *node, char **envp)
{
	t_cmd	*cmd;	

	cmd = node->content;
	if (node->next)
	{
		dup2(p->input, 0);
		dup2(f[1], 1);
	}
	else
	{
		dup2(p->output, 1);
		dup2(f[0], 0);
	}
	ft_exe(node, p);
	close(p->input);
	close(p->output);
	close(f[0]);
	close(f[1]);
	if (p->err_f == 0)
	{
		execve(cmd->pathtrack, cmd->cmds, envp);
		dup2(2, 1);
		ft_printf("pipex: %s: %s\n", strerror(errno), cmd->cmds[0]);
	}
	return (end_pip(p, NULL));
}

void	*ft_pipe(t_pip	*p, char **envp)
{
	t_list	*head;
	pid_t	pid;
	int		f[2];

	head = p->cmds;
	if (pipe(f) == -1)
		return (end_pip(p, NULL));
	while (head)
	{
		pid = fork();
		if (pid == -1)
			return (end_pip(p, NULL));
		else if (!pid)
			ft_child_process(p, f, head, envp);
		head = head->next;
	}
	close(p->output);
	close(p->input);
	close(f[0]);
	close(f[1]);
	while (wait(NULL) != -1)
		;
	return (NULL);
}
