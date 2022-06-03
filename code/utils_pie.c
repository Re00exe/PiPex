/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:45:45 by midfath           #+#    #+#             */
/*   Updated: 2022/06/02 20:16:25 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_cmd	*ft_cmd(char *pathtrack, char **cmd)
{
	t_cmd	*new;
	if(!cmd)
		return (NULL);
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->pathtrack = ft_strdup(pathtrack);
	if (pathtrack && !new->pathtrack)
	{
		free(pathtrack);
		return (NULL);
	}
	new->cmds = cmd;
	return (new);
}

t_list	*pip_lstnew(char *pathtrack, char **cmd)
{
	t_list	*new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content =  ft_cmd(pathtrack, cmd);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

int	search_cmd(t_pip *p, char *cmd, char **pathtrack)
{
	char	*prt;
	int		i;

	i = -1;
	prt = NULL;
	while (p->path && p->path[++i])
	{
		if (*pathtrack)
			free(*pathtrack);
		prt = ft_strjoin(p->path[i],  "/");
		if (!prt)
			return (-1);
		*pathtrack = ft_strjoin(prt, cmd);
		free(prt);
		if (!pathtrack)
			return (-1);
		if (access(*pathtrack, F_OK) == 0)
			break ;
	}
	if (!p->path || !p->path[i] || (access(*pathtrack, F_OK)))
	{
		free(*pathtrack);
		return (-1);
	}
	return (0);
}

void *end_pip(t_pip *p, char ***cmd, int err)
{
	if (err)
		ft_perror(err);
	else if (cmd)
		ft_matfreex(cmd);
	else if (p)
	{
		close(STDIN_FILENO);
		close(p->input);
		close(p->output);
		if (p->cmds)
			ft_lstclear(&p->cmds, free);
		else if (p)
			ft_matfreex(&p->path);
		free(p);
	}
	exit (0);
	return (0);
}


t_pip	*ft_pip_parma(int ac, char **av, char **envp)
{	
	int		i;
	t_pip	*p;

	i = 0;
	p = NULL;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	p = malloc(sizeof(struct s_pip));
	p->err_f = 0;
	if (!p)
		return(end_pip(p, NULL, NO_MEMORY));
	p->path = ft_split(&envp[i][5], ':');
	if (!p->path)
		return(end_pip(p, NULL, NO_PATH));
	p->input = open(av[1], O_RDONLY);
	if (p->input == -1)
	{
		perror("ERROR:");
		p->err_f = 1;
	}
	p->output = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (p->output == -1)
		return(end_pip(p, NULL, NO_FILE));
	if (access(av[ac - 1], F_OK) == -1 )
		return(end_pip(p, NULL, NO_FILE));
	if (access(av[ac - 1], R_OK) == -1)
		return(end_pip(p, NULL, NO_PERM));
	return(p);
}
