/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:54:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/17 03:11:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	scan_arg(t_pipex *data, int status);
void	split_args(t_pipex *data, char **argv);

void	init_data(t_pipex *data, char **argv, char **envp)
{
	if (!access(argv[1], F_OK) && data->fd.infile < 0)
		data->status.file1 = 1;
	data->fd.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd.outfile < 0)
	{
		print_error(PEERROR, 1);
		exit(EXIT_FAILURE);
	}
	data->input.argv = argv;
	split_args(data, argv);
	data->status.file1 = 0;
	data->status.code = 0;
	data->status.status_error = 0;
	data->status.space_cmd_first = 0;
	data->status.space_cmd_second = 0;
	data->status.error_child_one = 0;
	data->input.envp = envp;
	data->fd.infile = open(argv[1], O_RDONLY);
	return ;
}

void	split_args(t_pipex *data, char **argv)
{
	char	*tmp;

	data->status.space_cmd_first = 0;
	data->status.space_cmd_second = 0;
	tmp = replace_word(argv[2], ' ', 1);
	data->input.cmd1 = ft_split(tmp, ' ');
	free(tmp);
	invert_word(data->input.cmd1);
	if (data->input.cmd1[0] == NULL)
	{
		free(data->input.cmd1);
		data->input.cmd1 = ft_split(" ", 1);
		data->status.status_error = empty_cmd;
	}
	return ;
}
