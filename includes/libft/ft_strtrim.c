/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:22:14 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/11 21:40:34 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_exist_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}	

static size_t	skipleft(char const	*s1, char const	*set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (is_exist_in_set(set, s1[i]) != 1)
			break ;
		i++;
	}
	return (i);
}	

static size_t	skipright(char const	*s1, char const	*set)
{
	size_t	j;

	j = ft_strlen(s1) - 1;
	while (j >= 0)
	{
		if (is_exist_in_set(set, s1[j]) != 1)
			break ;
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	k = 0;
	i = skipleft(s1, set);
	if (i == ft_strlen(s1))
	{
		s = malloc(1);
		s[0] = '\0';
		return (s);
	}
	j = skipright(s1, set);
	s = malloc(j - i + 2);
	if (!s)
		return (NULL);
	while (i <= j)
		s[k++] = s1[i++];
	s[k] = '\0';
	return (s);
}
