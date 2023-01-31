/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:19:18 by maralons          #+#    #+#             */
/*   Updated: 2022/04/01 18:12:32 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	csize(int aux)
{
	int	count;

	count = 0;
	while (aux != 0)
	{
		count++;
		aux /= 10;
	}
	return (count);
}

static char	*fill_numero_asqueroso(char *num)
{
	num[0] = '-';
	num[1] = '2';
	num[2] = '1';
	num[3] = '4';
	num[4] = '7';
	num[5] = '4';
	num[6] = '8';
	num[7] = '3';
	num[8] = '6';
	num[9] = '4';
	num[10] = '8';
	num[11] = 0;
	return ((char *) num);
}

static char	*filltable(int n, int count, char *str)
{
	if (n < 0 && n != -2147483648)
	{
		str[0] = '-';
		n *= -1;
	}
	str[count] = 0;
	if (n == 0)
		str[count - 1] = (n % 10) + 48;
	while (n != 0)
	{
		str[count - 1] = (n % 10) + 48;
		n /= 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*num;
	int		aux;

	aux = n;
	count = 0;
	if (aux < 0 || aux == 0)
		count++;
	count += csize(aux);
	num = malloc(sizeof(char) * (count + 1));
	if (!num)
		return (NULL);
	if (n == -2147483648)
		num = fill_numero_asqueroso(num);
	else
		num = filltable(n, count, num);
	return (num);
}
