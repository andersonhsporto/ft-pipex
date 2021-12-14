/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:53:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 11:53:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_arg_cmd(t_pipex *data)
{
	data->input.cmd2 = ft_split(data->input.argv[3], ' ');
	replace_word(data->input.cmd2);
	if (data->input.cmd2[0] == NULL)
	{
		free(data->input.cmd2);
		data->input.cmd2 = ft_split(" ", '-');
		data->status.status_error = empty_cmd;
	}
	return ;
}
