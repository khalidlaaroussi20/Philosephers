/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:41:54 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/12 12:01:31 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;
	t_list	*newnode;

	head = NULL;
	if (lst && f)
	{
		temp = lst;
		while (temp)
		{
			if (f(temp -> content))
			{
				newnode = ft_lstnew(f(temp -> content));
				if (!newnode)
				{
					ft_lstclear(&head, del);
					return (NULL);
				}
				ft_lstadd_back(&head, newnode);
			}
			temp = temp -> next;
		}
	}
	return (head);
}
