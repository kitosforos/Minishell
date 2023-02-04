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

int	env_find(t_env *env, char *var)
{
    int		i;
	t_list	*tmp;

	tmp = env->env;
    i = ft_strlen(var);
	while (tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, var, i) == 0)
			return (1);
		tmp = tmp->next;
	}
	if (ft_strncmp((char *)tmp->content, var, i) == 0)
			return (1);
	return (0);
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	t_list	*node;
	int		i;

	exit_status = 0;
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

int	env_print(t_env *env, char *var)
{
	t_list	*tmp;

	tmp = env->env;
	if (!var || !env)
		return (EXIT_FAILURE);
	if (env_find(env, var))
	{
		while (tmp->next)
		{
			if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
				printf("%s\n", (char *)tmp->content + ft_strlen(var) + 1);
			tmp = tmp->next;
		}
		if (ft_strncmp(tmp->content, var, ft_strlen(var)) == 0)
				printf("%s\n", (char *)tmp->content + ft_strlen(var) + 1);
	}
	if (ft_strncmp(var, "?", 2) == 0)
		return (2);
	return (0);
}
