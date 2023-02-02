/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:14 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 18:00:18 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_find(Env *env, char *var)
{
    int i;

    i = ft_strlen(var);
	while (ft_strncmp(*env->env, var, i))
		env->env++;
	return (*env->env + i + 1);
}

Env	*env_init(char **envp)
{
	Env	*env;
	
	env = (Env *) malloc(sizeof(Env));
	if (!env)
		return NULL;

	env->env = envp;
	return env;
}

void	env_print(Env *env, char *var)
{
	char *content;
	if (!var)
		return ;
	
	content = env_find(env, var+1);
	
	
}