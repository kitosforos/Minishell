/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:48:57 by maralons          #+#    #+#             */
/*   Updated: 2022/03/26 17:22:09 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*tmp;

	if (lst)
	{
		head = ft_lstnew(f(lst->content));
		if (!head)
			return (NULL);
		tmp = lst->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (!new)
			{
				ft_lstclear(&tmp, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new);
			tmp = tmp->next;
		}
		return (head);
	}
	return (NULL);
}
