/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/18 19:30:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	data;

	if (argc != 5)
		error_exit(ARGERROR, 1);
	data.i.fd_infile = open(argv[1], O_RDONLY);
	if (!access(argv[1], F_OK) && data.i.fd_infile < 0)
		data.i.permission = 1;
	data.i.fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	data.j.cmd_1 = ft_split(argv[2], ' ');
	data.j.cmd_2 = ft_split(argv[3], ' ');
	data.i.status = 0;
	data.j.file1 = argv[1];
	data.j.env = envp;
	init_path_array(&data);
	init_pipe(&data);
	free_path(&data);
	exit(WEXITSTATUS(data.i.status));
	return (0);
}
