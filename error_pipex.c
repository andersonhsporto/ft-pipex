/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:15:06 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/12 02:56:54 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*find_shell(t_info *data)
{
	int	i;

	i = 0;
	while (data->j.env[i])
	{
		if (ft_memcmp(data->j.env[i], "SHELL=", 6) == 0)
		{
			data->j.shell = ft_strdup(ft_strrchr(data->j.env[i], '/') + 1);
			break ;
		}
		i++;
	}
}

void	error_cmd(t_info *data, int code)
{
	char	*temp_string;

	if (code == cmd_1)
	{
		temp_string = ft_strtjoin(ft_strjoin(data->j.shell, ": "),
				data->j.cmd_1[0], CMDERROR);
		ft_putstr_fd(temp_string, 2);
		free(temp_string);
	}
	if (code == cmd_2)
	{
		temp_string = ft_strtjoin(ft_strjoin(data->j.shell, ": "),
				data->j.cmd_2[0], CMDERROR);
		ft_putstr_fd(temp_string, 2);
		free(temp_string);
	}
	return ;
}

void	error_exit(char *message, int code)
{
	if (code == 1)
	{
		write(STDERR_FILENO, ARGERROR, ft_strlen(ARGERROR));
		exit(code);
	}
	if (code == 127)
	{
		write(STDERR_FILENO, ARGERROR, ft_strlen(ARGERROR));
		exit(127);
	}
	return ;
}

void	ps_error(char *errno)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}
