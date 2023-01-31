/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:20:17 by danicn            #+#    #+#             */
/*   Updated: 2022/04/01 20:52:28 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *u, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new;
	t_list	*l;

	if (u == NULL || f == NULL)
		return (NULL);
	l = NULL;
	while (u)
	{
		content = f(u->content);
		new = ft_lstnew(content);
		if (!(new))
		{
			if (del)
			{
				del(content);
				ft_lstclear(&l, del);
				return (NULL);
			}
		}
		ft_lstadd_back(&l, new);
		u = u->next;
	}
	return (l);
}
