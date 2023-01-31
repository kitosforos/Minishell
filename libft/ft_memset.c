/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:14:13 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/03 21:25:30 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)(b))[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main()
// {
// 	char x[] = "bue   na  dsf  ";
// 	memset(x, 66, 5);
// 	printf("%s", x);
// }