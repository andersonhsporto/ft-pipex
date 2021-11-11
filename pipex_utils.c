/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:57:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/10 23:07:37 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	child_1(t_info *data)
{
	dup2(data->i.fd_infile, STDIN_FILENO);
	dup2(data->i.pipefd[1], STDOUT_FILENO);
	close(data->i.fd_infile);
	close(data->i.pipefd[0]);
	execve(data->j.path_cmd_1, data->j.cmd_1, data->j.env);
}

void	child_2(t_info *data)
{
	dup2(data->i.pipefd[0], STDIN_FILENO);
	dup2(data->i.fd_outfile, STDOUT_FILENO);
	close(data->i.pipefd[1]);
	close(data->i.fd_outfile);
	execve(data->j.path_cmd_2, data->j.cmd_2, data->j.env);
}

void	init_pipe(t_info *data)
{
	pipe(data->i.pipefd);
	data->child1 = fork();
	if (data->child1 < 0)
		return (perror("teste"));
	if (data->child1 == 0)
		child_1(data);
	data->child2 = fork();
	if (data->child2 < 0)
		return (perror("Fork: "));
	if (data->child2 == 0)
		child_2(data);
	close(data->i.pipefd[0]);
	close(data->i.pipefd[1]);
	waitpid(data->child1, NULL, 0);
	waitpid(data->child2, NULL, 0);
	return ;
}
