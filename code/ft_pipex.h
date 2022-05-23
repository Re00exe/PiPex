/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:37:35 by midfath           #+#    #+#             */
/*   Updated: 2022/05/22 17:37:38 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../printf_dir/ft_printf.h"

/*struct to file with parmeters */

typedef struct s_pip
{
	int		input;
	int		output;
	char	**path;
	t_list	cmds;
}			t_pip;

/*get the parmeter from the main args*/
t_pip *ft_pip_parma(int ac, char **av,char **envp);

/*end the  process free and close files */
void *end_pip(t_pip *p, char **cmd);

#endif