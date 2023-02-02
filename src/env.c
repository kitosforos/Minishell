/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:14 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 20:01:52 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

Env	*env_init(char **envp)
{
	Env	*env;

	env = (Env *) malloc(sizeof(Env));
	if (!env)
		return (NULL);
	env->env = envp;
	return (env);
}

void	env_print(Env *env, char *var)
{
	char	*content;

	if (!var || !env)
		return ;
	content = getenv(var + 1);
	if (content)
		printf("%s\n", content);
}
