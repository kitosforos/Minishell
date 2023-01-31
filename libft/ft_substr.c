/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:02:06 by maralons          #+#    #+#             */
/*   Updated: 2022/04/01 18:43:11 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*str;
	int				i;
	unsigned int	dim;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	dim = ft_strlen(s) - start;
	if (dim <= len)
		len = dim;
	i = 0;
	str = malloc ((sizeof(char) * len + 1));
	if (!str)
		return (NULL);
	while (i < (int)len && start <= ft_strlen(s))
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
