/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:54:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/02 22:37:37 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_path_array(t_pipex *data, char **command);
static void	init_path(t_pipex *data, char **command);
static void	find_path(t_pipex *data, char **command);
static void	find_shell(t_pipex *data);

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
		init_path_array(data, command);
}

void	init_path_array(t_pipex *data, char **command)
{
	int	i;

	i = 0;
	while (data->input.envp[i])
	{
		if (ft_memcmp(data->input.envp[i], "PATH=", 5) == 0)
		{
			data->input.temp_string = ft_strdup
				(ft_strchr(data->input.envp[i], '=') + 1);
			init_path(data, command);
			break ;
		}
		i++;
	}
	return ;
}

static void	init_path(t_pipex *data, char **command)
{
	int		i;
	char	*temp_string;

	data->input.path = ft_split(data->input.temp_string, ':');
	free(data->input.temp_string);
	i = 0;
	while (data->input.path[i])
	{
		temp_string = ft_strdup(data->input.path[i]);
		free(data->input.path[i]);
		data->input.path[i] = ft_strjoin(temp_string, "/");
		free(temp_string);
		i++;
	}
	find_path(data, command);
	return ;
}

static void	find_path(t_pipex *data, char **command)
{
	int	i;

	i = 0;
	while (data->input.path[i])
	{
		data->input.temp_string = ft_strjoin
			(data->input.path[i], data->input.temp_cmd);
		if (!access(data->input.temp_string, F_OK))
			execve(data->input.temp_string, command, data->input.envp);
		free(data->input.temp_string);
		i++;
	}
	find_shell(data);
	error_cmd(data, command[0], CMDERROR);
	free(data->input.shell);
	free_pointer_array(data->input.path);
	free_pointer_array(data->input.cmd1);
	free_pointer_array(data->input.cmd2);
	exit(127);
}

void	find_shell(t_pipex *data)
{
	int		i;
	char	*temp_string;

	i = 0;
	while (data->input.envp[i])
	{
		if (ft_memcmp(data->input.envp[i], "SHELL=", 6) == 0)
		{
			temp_string = ft_strdup(ft_strrchr(data->input.envp[i], '/') + 1);
			data->input.shell = ft_strjoin(temp_string, ": ");
			free(temp_string);
			break ;
		}
		i++;
	}
}
