/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:57:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/18 00:40:41 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	error_cmd_one(t_info *data)
{
	if (data->i.permission == 1)
		error_cmd(data, data->j.file1, PEERROR);
	else
		error_cmd(data, data->j.file1, FILEERROR);
	close(STDIN_FILENO);
	exit(127);
}

void	child_one(t_info *data)
{
	int	i;

	i = dup2(data->i.fd_infile, STDIN_FILENO);
	if (i < 0)
		error_cmd_one(data);
	dup2(data->i.pipefd[1], STDOUT_FILENO);
	close(data->i.fd_infile);
	close(data->i.pipefd[0]);
	if (data->cmd_1 == 1)
	{
		execve(data->j.cmd_1, data->j.cmd_1, data->j.env);
	}
	else
	{
		error_cmd(data, data->j.cmd_1[0], CMDERROR);
		exit(127);
	}
}

void	child_two(t_info *data)
{
	dup2(data->i.fd_outfile, STDOUT_FILENO);
	dup2(data->i.pipefd[0], STDIN_FILENO);
	close(data->i.pipefd[1]);
	close(data->i.fd_outfile);
	if (data->cmd_2 == 1)
		execve(data->j.cmd_2, data->j.cmd_2, data->j.env);
	else
	{
		error_cmd(data, data->j.cmd_2[0], CMDERROR);
		exit(127);
	}
}

void	init_pipe(t_info *data)
{
	pipe(data->i.pipefd);
	data->child1 = fork();
	if (data->child1 < 0)
		return (perror("Fork: "));
	if (data->child1 == 0)
		child_one(data);
	data->child2 = fork();
	if (data->child2 < 0)
		return (perror("Fork: "));
	if (data->child2 == 0)
		child_two(data);
	close(data->i.pipefd[0]);
	close(data->i.pipefd[1]);
	waitpid(data->child1, &data->i.status, 0);
	waitpid(data->child2, &data->i.status, 0);
	return ;
}
