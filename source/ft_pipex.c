/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 12:12:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc == 5)
	{
		init_data(&data, argv, envp);
		init_pipe(&data);
		if (data.status.error_child_one == 0)
		{
			free_pointer_array(data.input.cmd1);
		}
		exit(WEXITSTATUS(data.status.code));
	}
	else
	{
		print_error(ARGERR, 1);
	}
	return (0);
}
