/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:28:23 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 22:15:38 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins2.h"

int	my_cd(char	*argv)
{
	if (chdir(argv) == 0)
		return (1);
	return (0);
}

int	my_export(char *args[], t_env *env)
{
	char	**words;
	char	**env_word;
	t_list	*tmp;

	tmp = env->env;
	words = ft_split(args[1], '=');
	env_word = ft_split(tmp->content, '=');
	if (env_find(env, words[0]))
	{
		while (ft_strncmp(words[0], env_word[0], ft_strlen(env_word[0])) != 0)
		{
			tmp = tmp->next;
			env_word = ft_split(tmp->content, '=');
		}
		tmp->content = args[1];
		return (EXIT_SUCCESS);
	}
	else
		export_add(args[1], env);
	return (EXIT_SUCCESS);
}

int	export_add(char *var, t_env *env)
{
	t_list	*node;	
	
	node = ft_lstnew(var);
	ft_lstadd_back(&env->env, node);
	return (EXIT_SUCCESS);
}

int	my_unset(char *args[], t_env *env)
{
	t_list 		*tmp;
	t_list 		*tmp2;
	int			flag;
	char		**env_word;

	flag = 0;
	tmp = env->env;
	tmp2 = env->env;
	env_word = ft_split(tmp->content, '=');
	if (env_find(env, args[1]))
	{
		while (ft_strncmp(args[1], env_word[0], ft_strlen(env_word[0])) != 0)
		{
			if (flag == 1)
				tmp2 = tmp2->next;
			tmp = tmp->next;
			env_word = ft_split(tmp->content, '=');
			flag = 1;
		}
		tmp2->next = tmp2->next->next;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}