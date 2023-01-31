/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:40:17 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/01 21:09:37 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_max_long(void)
{
	return (~0UL >> 1);
}

int	ft_atoi(const char *str)
{
	unsigned long	n;
	int				s;
	int				i;

	i = 0;
	n = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if (n > ft_max_long() && s == 1)
			return (-1);
		else if (n > ft_max_long() && s == -1)
			return (0);
	}
	return (s * n);
}
