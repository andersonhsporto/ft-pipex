/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:23:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/17 03:08:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_one(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

void	invert_word(char **matrix)
{
	int		i;
	char	*tmp;
	char	*tmp_u;

	i = 0;
	while (matrix[i])
	{
		if (is_one(matrix[i]))
		{
			ft_putstr_fd(matrix[i], 2);
			ft_putstr_fd("\n", 2);
			tmp = replace_word(matrix[i], 1, ' ');
			tmp_u = ft_strtrim(tmp, "'");
			free(matrix[i]);
			matrix[i] = ft_strdup(tmp_u);
			ft_putstr_fd(tmp, 2);
			ft_putstr_fd("\n", 2);
			free(tmp);
			free(tmp_u);
		}
		i++;
	}
	return ;
}

char	*replace_word(char *cmd, char one, char two)
{
	char	*string;
	int		i;

	string = ft_strdup(cmd);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\'')
		{
			i++;
			while (string[i] != '\'')
			{
				if (string[i] == one)
					string[i] = two;
				i++;
			}
		}
		i++;
	}
	return (string);
}

// int main(void)
// {
// 	char *teste = "teste ' '";

// 	char *casa = replace_word(teste, ' ', 'f');
// 	printf("%s", casa);
// }