/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:09:23 by maralons          #+#    #+#             */
/*   Updated: 2022/03/30 21:24:58 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		signo;
	long	numero;

	i = 0;
	signo = 1;
	numero = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		numero = numero * 10 + (str[i++] - '0');
		if (numero > 2147483647 && signo == 1)
			return (-1);
		else if (numero < -2147483649)
			return (0);
	}
	return ((int)(numero * signo));
}

// int main() {
// 	printf("%d\n", atoi("3747"));
// 	printf("%d\n", ft_atoi("     3747"));
// }
