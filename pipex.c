/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/04 05:01:40 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		exit(0);
	printf("%s\n", envp);
	return (0);
}
