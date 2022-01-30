/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:13:09 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/12 14:49:57 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	src_length = ft_strlen(src);
	if (!dstsize)
		return (src_length);
	dst_length = ft_strlen(dst);
	if (dstsize <= dst_length)
		return (dstsize + src_length);
	i = 0;
	while (src[i] && i < dstsize - dst_length - 1)
	{
		dst[i + dst_length] = src[i];
		i++;
	}
	dst[i + dst_length] = '\0';
	return (src_length + dst_length);
}
