/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:54:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/12 02:24:42 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_path(t_info *data, int i)
{
	while (data->split_path[i])
	{
		data->j.path_cmd_1 = ft_strjoin(data->split_path[i], data->j.cmd_1[0]);
		if (access(data->j.path_cmd_1, F_OK) == 0)
		{
			data->cmd_1 = 1;
			break ;
		}
		free(data->j.path_cmd_1);
		i++;
	}
	i = 0;
	while (data->split_path[i])
	{
		data->j.path_cmd_2 = ft_strjoin(data->split_path[i], data->j.cmd_2[0]);
		if (access(data->j.path_cmd_2, F_OK) == 0)
		{
			data->cmd_2 = 1;
			break ;
		}
		free(data->j.path_cmd_2);
		i++;
	}
}

static void	init_path(t_info *data)
{
	int		i;
	char	*temp_string;

	data->split_path = ft_split(data->j.temp_string, ':');
	i = 0;
	while (data->split_path[i])
	{
		temp_string = ft_strdup(data->split_path[i]);
		free(data->split_path[i]);
		data->split_path[i] = ft_strjoin(temp_string, "/");
		free(temp_string);
		i++;
	}
	find_path(data, 0);
	return ;
}

void	init_path_array(t_info *data)
{
	int	i;

	i = 0;
	data->cmd_1 = 0;
	data->cmd_2 = 0;
	find_shell(data);
	while (data->j.env[i])
	{
		if (ft_memcmp(data->j.env[i], "PATH=", 5) == 0)
		{
			data->j.temp_string = ft_strdup(ft_strchr(data->j.env[i], '=') + 1);
			init_path(data);
			break ;
		}
		i++;
	}
	return ;
}
