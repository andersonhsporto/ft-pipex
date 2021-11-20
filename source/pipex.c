/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/20 04:31:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static void	init_data(t_pipex *data, char **argv, char **envp)
{
	data->status.file1 = 0;
	data->status.code = 0;
	data->fd.infile = open(argv[1], O_RDONLY);
	if (!access(argv[1], F_OK) && data->fd.infile < 0)
		data->status.file1 = 1;
	data->fd.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd.outfile < 0)
	{
		print_error(PEERROR, 1);
		exit(EXIT_FAILURE);
	}
	data->input.argv = argv;
	data->input.envp = envp;
	data->input.cmd1 = ft_split(argv[2], ' ');
	data->input.cmd2 = ft_split(argv[3], ' ');
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		print_error(ARGERROR, 1);
	init_data(&data, argv, envp);
	init_pipe(&data);
	free_path(&data);
	exit(WEXITSTATUS(data.status.code));
	return (0);
}
