/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:14 by danicn            #+#    #+#             */
/*   Updated: 2023/02/25 19:56:41 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_free(t_env *env)
{
	t_list	*lst;

	while (env->env)
	{
		lst = env->env->next;
		free(env->env->content);
		free(env->env);
		env->env = lst;
	}
	free(env);
}

char	*env_find(t_env *env, char *var)
{
	t_list	*tmp;
	int		aux;
	char	*str;
	char	*wd;
	int		i;

	wd = malloc(sizeof(char) * ft_strlen(var) + 1);
	if (!wd)
		return (NULL);
	str = NULL;
	set_aux_i(var, &aux, &i);
	ft_strlcpy(wd, var, i + 1);
	tmp = env->env;
	while (tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, wd + 1,
				my_select((char *)tmp->content, wd + 1)) == 0)
			return (env_case_one(str, tmp, &aux, wd));
		tmp = tmp->next;
	}
	if (ft_strncmp((char *)tmp->content, wd + 1,
			my_select((char *)tmp->content, wd + 1)) == 0)
		return (env_case_one(str, tmp, &aux, wd));
	free(wd);		
	return ("");
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	t_list	*node;
	int		i;
	char	*str;
	
	i = 0;
	env = (t_env *) malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	str = (char *) malloc(sizeof(char) * ft_strlen(envp[0]) + 1);
	ft_strlcpy(str, envp[0], ft_strlen(envp[0]) + 1);
	env->env = ft_lstnew(str);
	env->envp = envp;
	env->exit_status = 0;
	while (envp[++i])
	{
		str = (char *) malloc(sizeof(char) * ft_strlen(envp[i]) + 1);
		ft_strlcpy(str, envp[i], ft_strlen(envp[i]) + 1);
		node = ft_lstnew(str);
		ft_lstadd_back(&env->env, node);
	}
	return (env);
}

int	env_print(t_env *env, char *var)
{
	t_list	*tmp;

	tmp = env->env;
	if (!var)
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
		return (ft_strlen(two));
	else
	{
		return (i);
	}
}
