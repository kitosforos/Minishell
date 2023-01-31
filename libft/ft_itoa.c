/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:57:17 by danicn            #+#    #+#             */
/*   Updated: 2022/04/01 18:48:29 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	final(long *i, char *s)
{
	if (ft_strlen(s) == 0)
		s[*i++] = '0';
	s[*i] = 0;
}

static long	ft_pow(long x, long exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (x);
	return (x * ft_pow(x, exp - 1));
}

static long	ncifras(long n)
{
	long	j;

	j = 0;
	while (n != 0)
	{	
		n /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	long	i;
	long	j;
	char	*s;
	long	l;

	l = (long)n;
	j = ncifras(l);
	s = (char *)malloc(sizeof(char) * (j + 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	if (l < 0)
	{
		s[i++] = '-';
		l *= -1;
	}
	if (l == 0)
		s[i++] = '0';
	while (j != 0)
	{
		s[i++] = (char)(l / ft_pow(10, j - 1)) + '0';
		l = l % ft_pow(10, --j);
	}
	final(&i, s);
	return (s);
}

// int main(){
// 	printf("%s", ft_itoa(0));
// }