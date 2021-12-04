/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:54:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/04 02:02:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_array(t_pipex *data, char **argv);
void	replace_word(char *string, char *old, char *new);

void	init_data(t_pipex *data, char **argv, char **envp)
{
	init_array(data, argv);
	data->status.file1 = 0;
	data->status.code = 0;
	data->status.status_error = 0;
	data->input.argv = argv;
	data->input.envp = envp;
	data->fd.infile = open(argv[1], O_RDONLY);
	if (!access(argv[1], F_OK) && data->fd.infile < 0)
		data->status.file1 = 1;
	data->fd.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd.outfile < 0)
	{
		print_error(PEERROR, 1);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	init_array(t_pipex *data, char **argv)
{
	// if (ft_strnstr(argv[2], "' '", ft_strlen(argv[2])))
	// {
	// 	//printf("teste2\n");
	// 	replace_word(argv[2], "' '", "0x0");
	// }
	// if (ft_strnstr(argv[3], "' '", ft_strlen(argv[3])))
	// {
	// 	//printf("teste\n");
	// 	replace_word(argv[3], "' '", "0x0");
	// }
	data->input.cmd1 = ft_split(argv[2], ' ');
	if (data->input.cmd1[0] == NULL)
	{
		free(data->input.cmd1);
		data->input.cmd1 = ft_split(" ", '-');
		data->status.status_error = empty_cmd;
	}
	data->input.cmd2 = ft_split(argv[3], ' ');
	if (data->input.cmd2[0] == NULL)
	{
		free(data->input.cmd2);
		data->input.cmd2 = ft_split(" ", '-');
		data->status.status_error = empty_cmd;
	}
	return ;
}

void	replace_word(char *string, char *old, char *new)
{
	int	i;
	int	j;
	int	new_counter;

	i = 0;
	j = 0;
	new_counter = 0;
	while (string[i] != '\0')
	{
		while (string[i + j] == old[j])
		{
			string[i + j] = new[new_counter];
			j++;
			new_counter++;
		}
		i++;
	}
	return ;
}
