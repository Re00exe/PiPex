/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:18:44 by midfath           #+#    #+#             */
/*   Updated: 2022/05/30 15:34:33 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_list *ft_parsing(int ac, char **av, t_pip *p)
{
	int		i;
	int		inx;
	t_list	*cmds;
	char	**cmd;
	char	*pathrack;
	
	i = 1;
	cmds = NULL;
	pathrack = NULL;
	while (++i < ac - 1)
	{
		p->cmds = cmds;
		cmd = ft_split(av[i], ' ');
		if (!cmd || !*cmd)
			return ((t_list *)end_pip(p, &cmd, CMD_FAIL));
		inx = search_cmd(p, *cmd, &pathrack);
		if (inx == -1)
			return ((t_list *)end_pip(p, &cmd, CMD_NOT_FOUND));
		ft_lstadd_back(&cmds, pip_lstnew(pathrack, cmd));
		free(pathrack);
		pathrack = NULL;
	}
	return (cmds);
}

int	main(int ac, char **av, char **envp)
{
	t_pip	*p;
	t_cmd	*c;
	
	c = NULL;
	p = NULL;
	if (ac != 5)
		return (*(int *)end_pip(p, NULL, INV_ARGS));
	if ((access(av[1], F_OK) == -1))
			return ((int)end_pip(p, NULL, NO_FILE));
	if ((access (av[1], R_OK) == -1))
			return ((int)end_pip(p, NULL, NO_PERM));
	 if (ac == 5 && **envp)
	{
		p = ft_pip_parma(ac, av, envp);
		p->cmds = ft_parsing(ac ,av, p);
		ft_pipe(p, envp);
	}
}
