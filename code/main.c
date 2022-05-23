/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:18:44 by midfath           #+#    #+#             */
/*   Updated: 2022/05/22 15:27:29 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pip	*p;

	if (ac != 5)
		{
			perror("ERROR : arguments !!!\n");
			return(0);
		}
	if ((access(av[1], F_OK) == -1) || \
		(access (av[1], R_OK) == -1))
		{
			perror("Error :");
			return (0);
		}
	else if (ac == 5 && **envp)
	{
		p = ft_pip_parma(ac, av, envp);
	}
}
