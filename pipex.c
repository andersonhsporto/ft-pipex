/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/05 02:01:33 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

void	find_path(t_info *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_memcmp(envp[i], "PATH=", 5) == 0)
		{
			data->string_path = ft_strdup(ft_strchr(envp[i], '=') + 1);
			break ;
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	data;

	if (argc != 5)
		return (-1);
	data.i.fd_infile = open(argv[1], O_RDONLY);
	data.i.fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.i.fd_infile < 0 || data.i.fd_outfile < 0)
		return (-1);
	find_path(&data, envp);
	printf("%s", data.string_path);
	return (0);
}
