/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:44:36 by danicn            #+#    #+#             */
/*   Updated: 2023/02/24 15:14:59 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"

void	split_free(char **strs)
{
	char	**aux;

	aux = strs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(aux);
}

void	program_free(t_minishell *mini)
{
	mini_free(mini);
}

void	errors(int argc, char **argv)
{
	if (argc != 1 || !(*argv))
		exit(EXIT_FAILURE);
}
