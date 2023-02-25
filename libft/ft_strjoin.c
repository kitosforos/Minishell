/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:24:04 by danicn            #+#    #+#             */
/*   Updated: 2023/02/25 17:53:36 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	int		es;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	es = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (es + 1));
	if (s1 == NULL || s2 == NULL || str == NULL)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (int)ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
// int main(){
// 	char s[] = "Hola", s1[] = "s2";
// 	printf("%s", ft_strjoin(s, s1));
// }
