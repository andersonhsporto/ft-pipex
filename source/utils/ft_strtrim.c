/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:49:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 02:49:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if (s1 == 0 || set == 0)
	{
		return (0);
	}
	while (*s1 != '\0' && (ft_strchr(set, *s1)))
	{
		s1++;
	}
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
	{
		end--;
	}
	return (ft_substr(s1, 0, end + 1));
}
