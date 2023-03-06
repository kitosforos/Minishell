/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:34:49 by marcos            #+#    #+#             */
/*   Updated: 2023/03/06 21:04:53 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes.h"

int	contains_quotes(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\"')
				return (1);
			else if (str[i][j] == '\'')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

void	iq_case_two(int *i, char *wd, int *j, char s)
{
	*i += 1;
	wd[*j] = s;
	*j += 1;
}
