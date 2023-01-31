/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:12:44 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/01 18:39:40 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char) c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

// int main(){
//    const char str[] = "benaskfllkakffdcxa";
//    const char ch = 'u';
//    char *ret;
//    ret = ft_memchr(str, ch, 40);
//    printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }