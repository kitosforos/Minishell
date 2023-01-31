/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:24:38 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/03/27 18:53:33 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (j <= i)
	{
		if (*str == (char) c)
			return (str);
		str++;
		j++;
	}
	return (NULL);
}

// int main(){
//    const char str[] = "benas";
//    const char ch = '\0';
//    char *ret;
//    ret = ft_strchr(str, ch);
//    printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }