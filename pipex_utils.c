/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:57:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/10 02:47:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	child_1(t_info *data)
{
	int end[2];

	dup2(data->i.fd_infile, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	close(end[0]);
	execve(data->j.path_cmd_1, data->j.cmd_1, data->j.env);
}

void	child_2(t_info *data, char **envp)
{
	int end[2];

	dup2(data->i.fd_infile, STDOUT_FILENO);
	dup2(end[1], STDIN_FILENO);
	close(end[1]);
	close(end[0]);
	execve(data->j.path_cmd_2, data->j.cmd_2, data->j.env);
}

void	init_pipe(t_info *data, char **envp)
{
	int status;
	int	end[2];

	pipe(end);
	data->child1 = fork();
	if (data->child1 < 0)
		return (perror("teste"));
    if (data->child1 == 0)
		child_1(data);
	data->child1 = fork();
	if (data->child1 < 0)
		return (perror("Fork: "));
    if (data->child1 == 0)
		child_2(data, envp);
	close(data->i.pipefd[0]);
	close(data->i.pipefd[1]);
	waitpid(data->child1, &status, 0);
	waitpid(data->child2, &status, 0);
	return ;
}
