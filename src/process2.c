/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:16:42 by marcos            #+#    #+#             */
/*   Updated: 2023/03/06 20:19:09 by maralons         ###   ########.fr       */
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

void	put_error_cmd(char *arr)
{
	ft_putstr_fd("orden <", STDERR_FILENO);
	ft_putstr_fd(arr, STDERR_FILENO);
	ft_putstr_fd("> no encontrada\n", STDERR_FILENO);
}
