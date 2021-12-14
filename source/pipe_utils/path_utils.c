/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:54:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 10:57:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_path(t_pipex *data, char **command);
static void	find_path(t_pipex *data, char **command);
static void	find_shell(t_pipex *data);

void	init_path_array(t_pipex *data, char **command)
{
	int	index;

	index = 0;
	while (data->input.envp[index])
	{
		if (ft_memcmp(data->input.envp[index], "PATH=", 5) == 0)
		{
			data->input.temp_string = ft_strdup(ft_strchr \
			(data->input.envp[index], '=') + 1);
			init_path(data, command);
			break ;
		}
		index++;
	}
	return ;
}

static void	init_path(t_pipex *data, char **command)
{
	int		index;
	char	*temp_string;

	data->input.path = ft_split(data->input.temp_string, ':');
	free(data->input.temp_string);
	index = 0;
	while (data->input.path[index])
	{
		temp_string = ft_strdup(data->input.path[index]);
		free(data->input.path[index]);
		data->input.path[index] = ft_strjoin(temp_string, "/");
		free(temp_string);
		index++;
	}
	find_path(data, command);
	return ;
}

static void	find_path(t_pipex *data, char **command)
{
	int	index;

	index = 0;
	while (data->input.path[index])
	{
		data->input.temp_string = ft_strjoin
			(data->input.path[index], data->input.temp_cmd);
		if (!access(data->input.temp_string, F_OK))
			execve(data->input.temp_string, command, data->input.envp);
		free(data->input.temp_string);
		index++;
	}
	if (data->status.status_error != empty_cmd)
	{
		find_shell(data);
		error_cmd(data, command[0], CMDERROR);
		free(data->input.shell);
	}
	free_pointer_array(data->input.path);
	free_pointer_array(data->input.cmd1);
	free_pointer_array(data->input.cmd2);
	exit(127);
}

void	find_shell(t_pipex *data)
{
	int		index;
	char	*temp_string;

	index = 0;
	while (data->input.envp[index])
	{
		if (ft_memcmp(data->input.envp[index], "SHELL=", 6) == 0)
		{
			temp_string = ft_strdup(ft_strrchr(data->input.envp[index], \
			'/') + 1);
			data->input.shell = ft_strjoin(temp_string, ": ");
			free(temp_string);
			break ;
		}
		index++;
	}
	return ;
}
