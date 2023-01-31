/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:11:02 by danicn            #+#    #+#             */
/*   Updated: 2022/03/31 15:06:30 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*n;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	if (len > (unsigned int)ft_strlen(s) && start == 0)
		return (ft_strdup(s));
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	j = 0;
	n = malloc(sizeof(char) * (len + 1));
	if (n == NULL)
		return (NULL);
	i = start;
	while (j < len)
	{
		n[j++] = s[i++];
	}
	n[len] = '\0';
	return ((char *)n);
}
// int main(){
// 	char a[] = "hola buenas";
// 	printf("%s", ft_substr(a, 2, 8));
// }
