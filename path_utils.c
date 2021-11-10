/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:54:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/10 00:54:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_path(t_info *data)
{
	int	i;

	i = 0;
	while (data->split_path[i])
	{
		data->j.path_cmd_1 = ft_strjoin(data->split_path[i], data->j.cmd_1[0]);
		if (access(data->j.path_cmd_1, F_OK) == 0)
			break ;
		free(data->j.path_cmd_1);
		i++;
	}
	i = 0;
	while (data->split_path[i])
	{
		data->j.path_cmd_2 = ft_strjoin(data->split_path[i], data->j.cmd_2[0]);
		if (access(data->j.path_cmd_2, F_OK) == 0)
			break ;
		free(data->j.path_cmd_2);
		i++;
	}
	return ;
}

static void	init_path(t_info *data, char *temp_string)
{
	char	**temp_array;
	int		i;

	temp_array = ft_split(temp_string, ':');
	data->split_path = ft_split(temp_string, ':');
	i = 0;
	while (temp_array[i])
	{
		data->split_path[i] = ft_strjoin(temp_array[i], "/");
		free(temp_array[i]);
		i++;
	}
	find_path(data);
	return ;
}

void	init_path_array(t_info *data, char **envp)
{
	char	*temp_string;
	int		i;

	temp_string = ft_strdup("");
	i = -1;
	while (envp[++i])
	{
		if (ft_memcmp(envp[i], "PATH=", 5) == 0)
		{
			temp_string = ft_strdup(ft_strchr(envp[i], '=') + 1);
			init_path(data, temp_string);
			free(temp_string);
			break ;
		}
	}
	return ;
}
