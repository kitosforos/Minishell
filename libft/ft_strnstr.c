/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:13:24 by maralons          #+#    #+#             */
/*   Updated: 2022/04/01 19:31:24 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (needle[0] == '\0')
		return ((char *)h);
	i = 0;
	j = 0;
	while (h[i] != 0 && i < len)
	{
		j = 0;
		if (h[i] == needle[j])
		{
			while (i + j < len && h[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return ((char *)&h[i]);
			}
		}
		i++;
	}
	return (0);
}
