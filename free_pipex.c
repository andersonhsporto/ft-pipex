/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:28:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/14 22:43:13 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_pointer_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return ;
}

void	free_path(t_info *data)
{
	free_pointer_array(data->j.cmd_1);
	free_pointer_array(data->j.cmd_2);
	free_pointer_array(data->split_path);
	free(data->j.temp_string);
	free(data->j.shell);
	if (data->cmd_1 == 1)
		free(data->j.path_cmd_1);
	if (data->cmd_2 == 1)
		free(data->j.path_cmd_2);
	return ;
}
