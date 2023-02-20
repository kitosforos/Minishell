/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:14 by danicn            #+#    #+#             */
/*   Updated: 2023/02/03 11:14:46 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_find(t_env *env, char *var)
{
	t_list	*tmp;
	int		aux;
	char	*str;
	char	*wd;
	int		i;

	wd = malloc(sizeof(char) * ft_strlen(var));
	i = 1;
	while (var[i] && var[i] != '$' && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	ft_strlcpy(wd, var, i + 1);
	aux = 0;
	tmp = env->env;
	while (tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, wd + 1, my_select((char *)tmp->content, wd + 1)) == 0)
		{
			str = (char *)tmp->content;
			while (str[aux] != '=')
				aux++;
			return ((char *)tmp->content + aux + 1);
		}
		tmp = tmp->next;
	}
	if (ft_strncmp((char *)tmp->content, wd + 1, my_select((char *)tmp->content, wd + 1)) == 0)
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

int	my_select(char *one, char *two)
{
	int	i;

	i = 0;
	while (one[i] != '=')
			i++;
	if ((int)ft_strlen(two) > i)
		return ft_strlen(two);
	else
	{
		return i;
	}
}