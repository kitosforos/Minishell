/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:44:14 by maralons          #+#    #+#             */
/*   Updated: 2022/03/25 18:27:59 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*item;
	size_t	i;

	i = 0;
	item = malloc(nitems * size);
	if (!item)
		return (NULL);
	ft_memset(item, 0, nitems * size);
	return (item);
}
