/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:13 by marcos            #+#    #+#             */
/*   Updated: 2023/03/01 19:28:11 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	echo_procces(char *argv, int *j, int *flag)
{
	if (*flag)
		printf(" ");
	*j = 0;
	while (argv[*j])
	{
		printf("%c", argv[*j]);
		*j += 1;
		*flag = 1;
	}
}

int	export_add(char *var, t_env *env)
{
	t_list	*node;
	t_list	*tmp;
	char	*str;

	tmp = env->env;
	str = (char *) malloc(sizeof(char) * (ft_strlen(var) + 1));
	if (!str)
		return (EXIT_FAILURE);
	ft_strlcpy(str, var, ft_strlen(var) + 1);
	node = ft_lstnew(str);
	if (!node)
		return (EXIT_FAILURE);
	ft_lstadd_back(&tmp, node);
	node = ft_lstlast(tmp);
	return (EXIT_SUCCESS);
}

int	uns_proc(char *args, t_list *tmp, t_list *tmp2, char **env_word)
{
	int	flag;

	flag = 0;
	while (ft_strncmp(args, env_word[0], ft_strlen(env_word[0])) != 0)
	{
		if (flag == 1)
			tmp2 = tmp2->next;
		tmp = tmp->next;
		split_free(env_word);
		env_word = ft_split(tmp->content, '=');
		if (!env_word)
			return (EXIT_FAILURE);
		flag = 1;
	}
	split_free(env_word);
	tmp2->next = tmp2->next->next;
	return (EXIT_SUCCESS);
}

int	my_unset(char *args[], t_env *env)
{
	t_list	*tmp;
	t_list	*tmp2;
	char	**env_word;
	char	*aux;

	tmp = env->env;
	tmp2 = env->env;
	aux = set_aux(args[1]);
	if (args[1][0] >= 48 && args[1][0] <= 57)
		return (exit_numeric(args));
	env_word = ft_split(tmp->content, '=');
	if (ft_strncmp(env_find(env, aux), "", 1) != 0)
	{
		free(aux);
		return (uns_proc(args[1], tmp, tmp2, env_word));
	}
	return (EXIT_FAILURE);
}

int	exit_numeric(char *cmds[])
{
	if (ft_strncmp(cmds[0], "unset", ft_strlen(cmds[0])) == 0)
		printf("%s: %s: invalid parameter name\n", cmds[0], cmds[1]);
	else
		printf("%s: not an identifier: %s\n", cmds[0], cmds[1]);
	return (EXIT_FAILURE);
}
