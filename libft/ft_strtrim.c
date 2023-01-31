/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:48:04 by maralons          #+#    #+#             */
/*   Updated: 2022/04/01 18:26:59 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	size;
	char			*dest;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	dest = ft_substr(s1, 0, size + 1);
	return (dest);
}

// int main()
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
// 	printf("%s", ft_strtrim(s1, " \n\t"));
// }