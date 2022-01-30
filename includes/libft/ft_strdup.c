/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:47:27 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/13 21:05:02 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_length;
	size_t	i;
	char	*coppy;

	s_length = ft_strlen(s1);
	coppy = (char *) malloc(sizeof(char) * (s_length + 1));
	if (!coppy)
		return (NULL);
	i = 0;
	while (i <= s_length)
	{
		coppy[i] = s1[i];
		i++;
	}
	return (coppy);
}
