/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:43:48 by maralons          #+#    #+#             */
/*   Updated: 2022/03/30 21:04:05 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	ch;
	size_t	i;

	p = (char *)s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (p[i] == ch)
			return (p + i);
		i++;
	}
	return (0);
}

// int main()
// {
// 	printf("%s\n", ft_memchr("holaquetal", 'a', 9));
// 	printf("%s", memchr("holaquetal", 'a', 9));
// }