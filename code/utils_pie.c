/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:45:45 by midfath           #+#    #+#             */
/*   Updated: 2022/05/22 19:53:27 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void *end_pip(t_pip *p, char **cmd)
{
	if (errno)
		perror("Error\n");
	if (cmd)
		ft_matfreex(cmd);
	if (p)
	{
		close(STDIN_FILENO);
		close(p->input);
		close(p->output);
		if (p)
			ft_lstclear(&p->cmds, free);
		if (p)
			ft_matfreex(&p->path);
		free(p);
	}
}


t_pip	*ft_pip_parma(int ac, char **av, char **envp)
{	
	int		i;
	t_pip	*p;

	i = 0;
	if (access(av[ac - 1], F_OK) == -1 || access(av[ac - 1], F_OK))
		return(end_pip(p, NULL));
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	p = malloc(sizeof(struct s_pip));
	if (!p)
		return(end_pip(p, NULL));
	p->path = ft_split(envp[i], ':');
	if (!p->path)
		return(end_pip(p, NULL));
	p->input = open(av[1], O_RDONLY);
	if (p->input == -1)
		return(end_pip(p, NULL));
	p->output = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (p->output == -1)
		return(end_pip(p, NULL));
	return(p);
}
