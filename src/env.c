/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:14 by danicn            #+#    #+#             */
/*   Updated: 2023/02/20 12:22:01 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void delete(void *p)
{
	if (p)
		free(p);	
}

void	env_free(t_env *env)
{
	t_list	*lst;
	
	while (env->env)
	{
		lst = env->env->next;
		free(env->env);
		env->env = lst;
	}
	free(env);
}

char	*env_find(t_env *env, char *var)
{
    int		i;
	t_list	*tmp;
	int		aux;
	char	*str;

	aux = 0;
	tmp = env->env;
    i = 0;
	while (var[i] && var[i] != ' ')
		i++;
	while (tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, var + 1, i - 2) == 0)
		{
			str = (char *)tmp->content;
			while (str[aux] != '=')
				aux++;
			return ((char *)tmp->content + aux + 1);
		}
		tmp = tmp->next;
	}
	if (ft_strncmp((char *)tmp->content, var + 1, i - 2) == 0)
	{
		str = (char *)tmp->content;
		while (str[aux] != '=')
			aux++;
		return ((char *)tmp->content + aux + 1);
	}
	return ("");
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
	env->exit_status = 0;
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
