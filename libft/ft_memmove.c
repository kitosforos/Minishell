/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:54:44 by maralons          #+#    #+#             */
/*   Updated: 2022/03/29 19:41:16 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	else
	{
		if (s < d)
		{
			while (++i <= n)
				d[n - i] = s[n - i];
		}
		else
		{
			while (n--)
				*d++ = *s++;
		}
		return (dest);
	}
}

// int main()
// {
// 	char str[50] = "This is string.h library function\n";
// 	char str2[50] = "This is string.h library function\n";
// 	char str3[50] = "IMBECIL";
// 	char str4[50] = "IMBECIL";
// 	printf("%s\n", memmove(str, str3, 3));
// 	printf("%s\n", ft_memmove(str2, str4, 3));
// }
