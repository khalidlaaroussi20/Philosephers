/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:07:18 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/12 15:39:13 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min_value(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	size_sub_str;
	char	*sub_str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub_str = malloc(1);
		sub_str[0] = '\0';
		return (sub_str);
	}
	size_sub_str = s_len - start + 1;
	size_sub_str = min_value(size_sub_str, len + 1);
	sub_str = (char *)malloc(size_sub_str);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, size_sub_str);
	return (sub_str);
}
