/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:50:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/10 00:28:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

# include <stdio.h> // REMOVER AO FINAL !!

typedef struct s_filedes
{
	int	fd_infile;
	int	fd_outfile;
	int pid_1;
	int pid_2;
}	t_filedes;

typedef struct s_strings
{
	char		**cmd_1;
	char		**cmd_2;
	char		*path_cmd_1;
	char		*path_cmd_2;
}	t_strings;

typedef struct s_info
{
	t_filedes	i;
	t_strings	j;
	char		**split_path;
}	t_info;

void	init_path_array(t_info *data, char **envp);

#endif