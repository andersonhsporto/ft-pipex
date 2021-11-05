/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/05 04:09:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//SOMENTE PARA TESTES
void	PRINT_STRUC(t_info *data)
{
	printf("fd  in %d\n", data->i.fd_infile);
	printf("fd out %d\n", data->i.fd_outfile);
	printf("%s\n", data->split_path[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	data;

	if (argc != 5)
		return (-1);
	data.i.fd_infile = open(argv[1], O_RDONLY);
	data.i.fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.i.fd_infile < 0 || data.i.fd_outfile < 0 )
		return (-1);
	init_path_array(&data, envp);
	PRINT_STRUC(&data);
	return (0);
}
