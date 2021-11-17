/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:57:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/17 02:04:00 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	child_1(t_info *data)
{
	dup2(data->i.pipefd[1], STDOUT_FILENO);
	dup2(data->i.fd_infile, STDIN_FILENO);
	close(data->i.fd_infile);
	close(data->i.pipefd[0]);
	if (data->cmd_1 == 1)
		execve(data->j.path_cmd_1, data->j.cmd_1, data->j.env);
	error_cmd(data, cmd_1);
	exit(EXIT_FAILURE);
}

void	child_2(t_info *data)
{
	dup2(data->i.fd_outfile, STDOUT_FILENO);
	dup2(data->i.pipefd[0], STDIN_FILENO);
	close(data->i.pipefd[1]);
	close(data->i.fd_outfile);
	if (data->cmd_2 == 1)
		execve(data->j.path_cmd_2, data->j.cmd_2, data->j.env);
	error_cmd(data, cmd_2);
}

void	init_pipe(t_info *data)
{
	int		status;

	pipe(data->i.pipefd);
	data->child1 = fork();
	if (data->child1 < 0)
		return (perror("Fork: "));
	if (data->child1 == 0)
		child_1(data);
	data->child2 = fork();
	if (data->child2 < 0)
		return (perror("Fork: "));
	if (data->child2 == 0)
		child_2(data);
	close(data->i.pipefd[0]);
	close(data->i.pipefd[1]);
	waitpid(data->child1, &status, 0);
	waitpid(data->child2, &status, 0);
	exit(status);
	return ;
}
