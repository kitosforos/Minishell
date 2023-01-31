/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:45:09 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/01 18:44:40 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	lenn(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *h, const char *need, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	c;
	char			*hay;

	hay = (char *) h;
	c = lenn(need);
	i = 0;
	while (i < len && hay[i] && c != 0)
	{
		j = 0;
		k = i;
		if (hay[i] == (char) need[j])
		{
			while ((j < c) && k < len && hay[k++] == (char) need[j])
				j++;
			if (j == c)
				return (&hay[i]);
		}
		i++;
	}
	if (!c)
		return (hay);
	return (NULL);
}

// int main()
// {
// 	char a[] = "Buenos dias compa", b[] = "dias";
// 	printf("%s", ft_strnstr(a, b, 10));
// }