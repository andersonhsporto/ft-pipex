/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:26:31 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 11:26:33 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

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
