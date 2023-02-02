/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:14 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 22:13:54 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_find(t_env *env, char *var)
{
    int		i;

    i = ft_strlen(var);
	while (ft_strncmp((char *)env->env->content, var, i) && env->env->next)
		env->env = env->env->next;
	return ((char *)env->env->content + i + 1);
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	t_list	*node;
	int		i;

	i = 1;
	env = (t_env *) malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->env = ft_lstnew(envp[0]);
	env->envp = envp;
	while (envp[i])
	{
		node = ft_lstnew(envp[i++]);
		ft_lstadd_back(&env->env, node);
	}
	return (env);
}

void	env_print(t_env *env, char *var)
{
	char	*content;

	if (!var || !env)
		return ;
	content = getenv(var + 1);
	if (content)
		printf("%s\n", content);
}
