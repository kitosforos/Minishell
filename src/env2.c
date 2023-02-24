/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:14:53 by marcos            #+#    #+#             */
/*   Updated: 2023/02/24 17:16:30 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	delete(void *p)
{
	if (p)
		free(p);
}

char	*env_case_one(char *str, t_list *tmp, int *aux, char *wd)
{
	str = (char *)tmp->content;
	while (str[*aux] != '=')
		*aux += 1;
	free(wd);
	return ((char *)tmp->content + *aux + 1);
}

void	set_aux_i(char *var, int *aux, int *i)
{
	*i = 1;
	while (var[*i] && var[*i] != '$' && (ft_isalnum(var[*i]) || var[*i] == '_'))
		*i += 1;
	*aux = 0;
}
