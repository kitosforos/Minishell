/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:38:31 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/01 18:20:24 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (b < a)
	{
		while (++i <= n)
			a[n - i] = b[n - i];
	}
	else
	{
		while (n--)
			*a++ = *b++;
	}
	return (dst);
}
// int main()
// {
// 	char x[] = "bue   na  dsf  ";
// 	char y[] = "klk pap  ";
// 	ft_memmove(x, x + 2, 5);
// 	printf("%s", x);
// }
