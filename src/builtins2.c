/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:28:23 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 21:51:18 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins2.h"

int	my_export(char *args[], t_env *env)
{
	char	**words;
	char	**env_word;
	int		i;

	i = 0;
	words = ft_split(args[1], '=');
	env_word = ft_split(env->env->content, '=');
	if (getenv(words[0]))
	{
		while (strcmp(words[0], env_word[0]) != 0)
		{
			i++;
			env->env = env->env->next;
			env_word = ft_split(env->env->content, '=');
		}
		env->env->content = args[1];
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
