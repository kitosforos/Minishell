/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:03:14 by danicn            #+#    #+#             */
/*   Updated: 2022/03/27 17:29:53 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (lst && del)
	{
		while ((*lst))
		{
			l = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = l;
		}
	}
}
