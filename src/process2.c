/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:16:42 by marcos            #+#    #+#             */
/*   Updated: 2023/03/01 12:17:06 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	desprepare_pipes(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 17)
				args[i][j] = '|';
			if (args[i][j] == 18)
				args[i][j] = '<';
			if (args[i][j] == 19)
				args[i][j] = '>';
			j++;
		}
		i++;
	}
}
