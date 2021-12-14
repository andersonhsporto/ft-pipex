/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:54:39 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 02:55:47 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		is_space(char *string);
void	scan_arg(t_pipex *data, int status);
void	split_args(t_pipex *data, char **argv);
void	replace_word(char **command);

void	init_data(t_pipex *data, char **argv, char **envp)
{
	data->fd.infile = open(argv[1], O_RDONLY);
	if (!access(argv[1], F_OK) && data->fd.infile < 0)
		data->status.file1 = 1;
	data->fd.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd.outfile < 0)
	{
		print_error(PEERROR, 1);
		exit(EXIT_FAILURE);
	}
	data->input.argv = argv;
	scan_arg(data, 2);
	scan_arg(data, 3);
	split_args(data, argv);
	data->status.file1 = 0;
	data->status.code = 0;
	data->status.status_error = 0;
	data->status.space_cmd_first = 0;
	data->status.space_cmd_second = 0;
	data->input.envp = envp;
	return ;
}

int	is_space(char *string)
{
	int	index;
	int	status;

	index = 0;
	status = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '\'')
		{
			status++;
		}
		index++;
	}
	if (status == 2 || status == 4)
		return (1);
	else
		return (0);
}

void	scan_arg(t_pipex *data, int status)
{
	int	index;
	int	j_index;

	index = 0;
	while (data->input.argv[status][index])
	{
		if (data->input.argv[status][index] == '\'')
		{
			j_index = index + 1;
			while (data->input.argv[status][j_index] == ' ')
			{
				data->input.argv[status][j_index] = '`';
				j_index++;
			}
			if (status == 2)
				data->status.space_cmd_first = cmd_space;
			if (status == 3)
				data->status.space_cmd_second = cmd_space;
			return ;
		}
		index++;
	}
	return ;
}

void	split_args(t_pipex *data, char **argv)
{
	data->status.space_cmd_first = 0;
	data->status.space_cmd_second = 0;
	data->input.cmd1 = ft_split(argv[2], ' ');
	replace_word(data->input.cmd1);
	if (data->input.cmd1[0] == NULL)
	{
		free(data->input.cmd1);
		data->input.cmd1 = ft_split(" ", '-');
		data->status.status_error = empty_cmd;
	}
	data->input.cmd2 = ft_split(argv[3], ' ');
	replace_word(data->input.cmd2);
	if (data->input.cmd2[0] == NULL)
	{
		free(data->input.cmd2);
		data->input.cmd2 = ft_split(" ", '-');
		data->status.status_error = empty_cmd;
	}
	return ;
}

void	replace_word(char **command)
{
	int		index;
	int		j_index;
	char	*temp;

	index = -1;
	while (command[++index])
	{
		j_index = -1;
		while (command[index][++j_index])
		{
			if (command[index][j_index] == '`')
			{
				while (command[index][j_index] == '`')
				{
					command[index][j_index] = ' ';
					j_index++;
				}
				temp = ft_strdup(command[index]);
				free(command[index]);
				command[index] = ft_strtrim(temp, "\'");
				free(temp);
				return ;
			}
		}
	}
}

// void	replace_word(char *string, char *old, char *new)
// {
// 	int	index;
// 	int	j_index;
// 	int	new_counter;

// 	index = 0;
// 	j_index = 0;
// 	new_counter = 0;
// 	while (string[index] != '\0')
// 	{
// 		while (string[index + j_index] == old[j_index])
// 		{
// 			string[index + j_index] = new[new_counter];
// 			new_counter++;
// 			j_index++;
// 		}
// 		index++;
// 	}
// 	return ;
// }

// void	replace_word_vector(char **vector, char *old, char *new)
// {
// 	int	index;

// 	index = 0;
// 	while (vector[index])
// 	{
// 		if ((ft_strnstr(vector[index], "' '", ft_strlen(vector[index]))))
// 		{
// 			replace_word(vector[index], old, new);
// 		}
// 		index++;
// 	}
// 	return ;
// }

