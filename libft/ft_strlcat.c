/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:53:40 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/03/31 14:26:32 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = 0;
	j = dest_len;
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] && dest_len + i < size - 1)
			dst[j++] = src[i++];
		dst[j] = 0;
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
