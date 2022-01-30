/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:32:44 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/12 12:04:38 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*list;

	i = 0;
	list = malloc(count * size);
	if (list == NULL)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)list)[i] = '\0';
		i++;
	}
	return (list);
}
