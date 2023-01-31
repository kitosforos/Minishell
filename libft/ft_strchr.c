/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:28:23 by maralons          #+#    #+#             */
/*   Updated: 2022/04/05 17:18:58 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != 0)
		i++;
	j = 0;
	while (j <= i)
	{
		if (*str == (char)c)
			return (str);
		str++;
		j++;
	}
	return (0);
}

//  int main()
//  {
// 	printf("%s", ft_strchr("holaquetal", '\0'));
// }