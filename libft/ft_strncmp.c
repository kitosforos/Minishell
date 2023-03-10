/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:56:56 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/02/24 13:58:41 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!s1)
		return (0 - ft_strlen(s2));
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - *s2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
