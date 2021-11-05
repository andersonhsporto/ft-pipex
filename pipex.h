/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:50:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/05 03:00:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h> // REMOVER AO FINAL !!

typedef struct s_filedes
{
	int	fd_infile;
	int	fd_outfile;
	int	j;
}	t_filedes;

typedef struct s_info
{
	t_filedes	i;
	char		**split_path;
}	t_info;

void	init_path_array(t_info *data, char **envp);

#endif