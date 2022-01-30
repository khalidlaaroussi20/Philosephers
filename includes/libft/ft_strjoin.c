/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:56:46 by klaarous          #+#    #+#             */
/*   Updated: 2022/01/09 06:07:24 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	coppy_str(char const	*s1, char *s2, size_t startIndex)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		s2[i + startIndex] = s1[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len_str_join;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len_str_join = s1_len + s2_len + 1;
	str_join = malloc(len_str_join);
	if (!str_join)
		return (NULL);
	coppy_str(s1, str_join, 0);
	coppy_str(s2, str_join, s1_len);
	str_join[len_str_join - 1] = '\0';
	return (str_join);
}
