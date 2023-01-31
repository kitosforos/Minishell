/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:42:25 by maralons          #+#    #+#             */
/*   Updated: 2022/03/24 08:53:58 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		cuenta;
	int		i;
	char	*copia;

	cuenta = 0;
	i = 0;
	while (src[cuenta] != '\0')
		cuenta++;
	copia = (char *) malloc (sizeof(char) * (cuenta + 1));
	if (!copia)
		return (NULL);
	while (src[i] != '\0')
	{
		copia[i] = src[i];
		i++;
	}
	copia[i] = '\0';
	return (copia);
}
