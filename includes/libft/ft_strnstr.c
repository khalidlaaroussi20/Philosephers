/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:26:25 by klaarous          #+#    #+#             */
/*   Updated: 2022/01/09 03:16:16 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	i = 0;
	while (i <= len - len_needle && haystack[i])
	{
		if (ft_strncmp(haystack + i, needle, len_needle) == 0)
		{
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
