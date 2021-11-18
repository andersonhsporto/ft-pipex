/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:15:06 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/17 23:59:25 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_shell(t_info *data)
{
	int		i;
	char	*temp_string;

	i = 0;
	while (data->j.env[i])
	{
		if (ft_memcmp(data->j.env[i], "SHELL=", 6) == 0)
		{
			temp_string = ft_strdup(ft_strrchr(data->j.env[i], '/') + 1);
			data->j.shell = ft_strjoin(temp_string, ": ");
			free(temp_string);
			break ;
		}
		i++;
	}
}

void	error_cmd(t_info *data, char *arg, char *message)
{
	char	*temp_string;

	temp_string = ft_strtjoin(data->j.shell,
			arg, message);
	ft_putstr_fd(temp_string, 2);
	free(temp_string);
	return ;
}

void	error_exit(char *message, int code)
{
	if (code == 1)
	{
		write(STDERR_FILENO, ARGERROR, ft_strlen(ARGERROR));
		exit(code);
	}
	return ;
}

void	ps_error(char *errno)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}
