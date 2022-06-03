/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c 1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:14:47 by midfath           #+#    #+#             */
/*   Updated: 2022/05/29 12:52:18 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

void	*ft_child_process(t_pip *p, int f[2], t_list *node, char **envp)
{
	t_cmd	*cmd;

	cmd = node->content;
	close(f[0]);
	if (node->next && dup2(f[1], STDOUT_FILENO) == -1)
		return (end_pip(p, NULL, DUP_ERR));
	if (!node->next && dup2(p->output, STDOUT_FILENO) == -1)
		return (end_pip(p, NULL, DUP_ERR));
	close(f[1]);
	close(p->input);
	close(p->output);
	execve(cmd->pathtrack, cmd->cmds, envp);
	return (end_pip(p, NULL, END));
}

void	*ft_pipe(t_pip	*p, char **envp)
{
	pid_t	pid;
	int		f[2];
	t_list	*head;

	head = p->cmds;
	if (dup2(p->input, STDIN_FILENO) == -1)
		p->err_f = 1;
	close(p->input);
	while (head)
	{
		if (p->err_f)
			head = head->next;
		else if (pipe(f) == -1)
			return (end_pip(p, NULL, DUP_ERR));
		pid = fork();
		if (pid == -1)
			return (end_pip(p, NULL, DUP_ERR));
		else if (!pid)
			ft_child_process(p, f, head, envp);
		close (f[1]);
		if (head->next && dup2(f[0],STDIN_FILENO) == -1)
			return (end_pip(p, NULL, DUP_ERR));
		close(f[0]);
		head = head->next;
	}
	while (wait(NULL) != -1)
		;
	return (NULL);
}

void	ft_perror(int err)
{
	ft_putstr_fd("pipex: ", 2);
	if (err == CMD_NOT_FOUND)
		ft_putstr_fd("command not found: ", 2);
	else if (err == NO_FILE)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (err == NO_PERM)
		ft_putstr_fd("permission denied: ", 2);
	else if (err == CMD_FAIL)
		ft_putstr_fd("command failed: ", 2);
	else if (err == INV_ARGS)
		ft_putstr_fd("invalid number of arguments", 2);
	else if (err == NO_MEMORY)
		ft_putstr_fd("no memory left on device", 2);
	else if (err == DUP_ERR)
		ft_putstr_fd("could not dup fd", 2);
	else if (err == PIPE_ERR)
		ft_putstr_fd("could not create pipe", 2);
	else if (err == FORK_ERR)
		ft_putstr_fd("could not fork process", 2);
	else if (err == NO_PATH)
		ft_putstr_fd("PATH variable is not set", 2);
	ft_putstr_fd("\n", 2);
}
