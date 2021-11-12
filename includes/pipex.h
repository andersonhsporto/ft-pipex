/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:50:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/12 00:53:18 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <string.h>

# include "../libft/libft.h"

# define ARGERROR "Should be executed this way: ./pipex file1 cmd1 cmd2 file2\n"

# include <stdio.h> // REMOVER AO FINAL !!

typedef struct s_filedes
{
	int	fd_infile;
	int	fd_outfile;
	int	pipefd[2];
	int	pid_1;
	int	pid_2;
}	t_filedes;

typedef struct s_strings
{
	char		**cmd_1;
	char		**cmd_2;
	char		*path_cmd_1;
	char		*path_cmd_2;
	char		*temp_string;
	char		**env;
}	t_strings;

typedef struct s_info
{
	t_filedes	i;
	t_strings	j;
	pid_t		child1;
	pid_t		child2;
	char		**split_path;
	int			cmd_1;
	int			cmd_2;
}	t_info;

void	init_path_array(t_info *data);
void	init_pipe(t_info *data);

void	error_exit(char *message, int code);
#endif