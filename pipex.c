/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/10 00:22:47 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

//SOMENTE TESTES
void	PRINT_STRUC(t_info *data)
{
	printf("fd  in %d\n", data->i.fd_infile);
	printf("fd out %d\n", data->i.fd_outfile);
	printf("%s\n", data->split_path[3]);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	data;

	if (argc != 5)
		return (-1); // adicionar função de erro!
	data.i.fd_infile = open(argv[1], O_RDONLY);
	data.i.fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	data.cmd_1 = ft_split(argv[3], ' ');
	data.cmd_2 = ft_split(argv[4], ' ');
	if (data.i.fd_infile < 0 || data.i.fd_outfile < 0)
		return (-1);
	init_path_array(&data, envp);
	PRINT_STRUC(&data);
	return (0);
}
