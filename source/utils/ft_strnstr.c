/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:34:38 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/06 21:07:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) > ft_strlen(haystack))
	{
		return (0);
	}
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	while (len >= ft_strlen(needle) && *haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
