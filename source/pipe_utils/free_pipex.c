/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:28:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/13 19:50:13 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pointer_array(char	**array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		array[index] = NULL;
		index++;
	}
	free(array);
	return ;
}

void	free_path(t_pipex *data)
{
	free_pointer_array(data->input.cmd1);
	free_pointer_array(data->input.cmd2);
	return ;
}