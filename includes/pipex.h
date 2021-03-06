/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:50:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/17 02:35:35 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

# include "utils.h"

# define ARGERR	"Should be executed this way:\n ./pipex file1 cmd1 cmd2 file2\n"
# define CMDERROR	": command not found\n"
# define FILEERROR	": no such file or directory\n"
# define PEERROR	": permission denied\n"
# define ECHILD		10

enum e_status
{
	fork_success,
	error,
	empty_cmd,
	cmd_error,
	cmd_space,
};

enum e_pipe
{
	pipe_read,
	pipe_write
};

typedef struct s_process
{
	pid_t	command_1;
	pid_t	command_2;
}	t_process;

typedef struct s_condition
{
	int	file1;
	int	code;
	int	status_error;
	int	space_cmd_first;
	int	space_cmd_second;
	int	error_child_one;
}	t_condition;

typedef struct s_args
{
	char	**argv;
	char	**envp;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*shell;
	char	*temp_string;
	char	*temp_cmd;
}	t_args;

typedef struct s_fildes
{
	int	infile;
	int	outfile;
	int	tube[2];
}	t_fildes;

typedef struct s_pipex
{
	t_args		input;
	t_fildes	fd;
	t_condition	status;
	t_process	pid;
}	t_pipex;

void	print_error(char *message, int exit_code);
void	put_error(int code);
void	error_cmd(t_pipex *data, char *arg, char *message);

void	init_pipe(t_pipex *data);

void	init_data(t_pipex *data, char **argv, char **envp);
char	*replace_word(char *cmd, char one, char two);
void	invert_word(char **matrix);

void	init_path_array(t_pipex *data, char **command);

void	free_pointer_array(char	**array);

void	find_shell(t_pipex *data);

void	init_arg_cmd(t_pipex *data);

#endif