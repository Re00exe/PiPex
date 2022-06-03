/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:37:35 by midfath           #+#    #+#             */
/*   Updated: 2022/06/02 13:34:46 by midfath          ###   ########.fr       */
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

/* Enum for error handling */
enum e_pipex_error
{
	END = 1,
	CMD_NOT_FOUND = 0,
	NO_FILE = -1,
	NO_PERM = -2,
	INV_ARGS = -3,
	NO_MEMORY = -4,
	PIPE_ERR = -5,
	DUP_ERR = -6,
	FORK_ERR = -7,
	NO_PATH = -8,
	CMD_FAIL = -9
};

/*struct to file with parmeters */

typedef struct s_pip
{
	int		input;
	int		output;
	char	**path;
	t_list	*cmds;
	int		err_f;
}			t_pip;

typedef	struct  s_cmd
{
	char *pathtrack;
	char **cmds;
}		t_cmd;

/*get the parmeter from the main args*/
t_pip *ft_pip_parma(int ac, char **av,char **envp);

/*end the  process free and close files */
void *end_pip(t_pip *p, char ***cmd, int err);

/*parse the cmmds and finde them*/
t_list *ft_parsing(int ac, char **av, t_pip *p);

/*search for the path abd return the index of it */
int	search_cmd(t_pip *p, char *cmd, char **pathtrack);

/*creat a new element of t_pip struct*/
t_list	*pip_lstnew(char *pathtrack, char **cmd);

/*creat cmd node and  init it with the path*/
t_cmd	*ft_cmd(char *pathtrack, char **cmd);

/*connect the output of the child processess with the input of the parent processess*/
void	*ft_pipe(t_pip	*p, char **envp);

/*executet the cmd to the parent process output*/
void	*ft_child_process(t_pip *p, int	f[2], t_list *node, char **envp);

/*printf the error*/
void	ft_perror(int err);

#endif