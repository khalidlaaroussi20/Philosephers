/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:42:00 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/11 10:22:38 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (len != 0)
	{
		if (&dst[0] < &src[0])
		{
			ft_memcpy(dst, src, len);
		}
		else
		{
			i = len - 1;
			while (i != 0)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i--;
			}
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
