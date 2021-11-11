/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:15:06 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/11 02:13:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

