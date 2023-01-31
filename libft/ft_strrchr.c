/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:47:25 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/04/01 18:44:28 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if (*str == (char) c)
			return (str);
		str--;
		i--;
	}
	return (NULL);
}

// int main(){
//    const char str[] = "http://www.tutorialspoint.com";
//    const char ch = 'o';
//    char *ret;
//    ret = strrchr(str, ch);
//    printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }