/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:57:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/13 19:49:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	start_cmd_one(t_pipex *data);
void	start_cmd_two(t_pipex *data);
void	start_command(t_pipex *data, char **command);

void	init_pipe(t_pipex *data)
{
	pipe(data->fd.tube);
	data->pid.command_1 = fork();
	if (data->pid.command_1 < 0)
		put_error(10);
	if (data->pid.command_1 == fork_success)
		start_cmd_one(data);
	data->pid.command_2 = fork();
	if (data->pid.command_2 < 0)
		put_error(10);
	if (data->pid.command_2 == fork_success)
		start_cmd_two(data);
	close(data->fd.tube[0]);
	close(data->fd.tube[1]);
	waitpid(data->pid.command_1, &data->status.code, 0);
	waitpid(data->pid.command_2, &data->status.code, 0);
	return ;
}

void	start_cmd_one(t_pipex *data)
{
	int	index;

	index = dup2(data->fd.infile, STDIN_FILENO);
	if (index < 0)
	{
		if (data->status.file1 == 1)
			error_cmd(data, data->input.argv[1], PEERROR);
		else
			error_cmd(data, data->input.argv[1], FILEERROR);
		close(STDIN_FILENO);
		exit(127);
	}
	dup2(data->fd.tube[1], STDOUT_FILENO);
	close(data->fd.infile);
	close(data->fd.tube[0]);
	start_command(data, data->input.cmd1);
	return ;
}

void	start_cmd_two(t_pipex *data)
{
	dup2(data->fd.outfile, STDOUT_FILENO);
	dup2(data->fd.tube[0], STDIN_FILENO);
	close(data->fd.tube[1]);
	close(data->fd.outfile);
	start_command(data, data->input.cmd2);
	return ;
}

void	start_command(t_pipex *data, char **command)
{
	int	access_return;

	access_return = access(command[0], F_OK);
	data->input.temp_cmd = command[0];
	if ((access_return == 0) && ft_strrchr(command[0], '/'))
	{
		execve(*command, command, data->input.envp);
	}
	else
	{
		init_path_array(data, command);
	}
}
