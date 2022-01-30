/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:26:30 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/11 21:35:40 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*currnode;
	t_list	*nextnode;

	if (!lst || !del)
		return ;
	if (*lst)
	{
		currnode = *lst;
		while (currnode)
		{
			nextnode = currnode -> next;
			ft_lstdelone(currnode, del);
			currnode = nextnode;
		}
	}
	*lst = NULL;
}
