/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:15:06 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/20 03:37:37 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *message, int exit_code)
{
	ft_putstr_fd(message, 2);
	exit(exit_code);
}

void	put_error(int code)
{
	char	*string_error;

	string_error = strerror(code);
	perror(string_error);
	exit(EXIT_FAILURE);
}

void	error_cmd(t_pipex *data, char *arg, char *message)
{
	char	*temp_string;

	temp_string = ft_strtjoin(data->input.shell,
			arg, message);
	ft_putstr_fd(temp_string, 2);
	free(temp_string);
	return ;
}
