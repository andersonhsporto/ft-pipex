/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:57:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/05 03:02:04 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
