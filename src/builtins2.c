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
	int		i;

	tmp = env->env;
	i = 0;
	words = ft_split(args[1], '=');
	env_word = ft_split(tmp->content, '=');
	if (getenv(words[0]))
	{
		while (strcmp(words[0], env_word[0]) != 0)
		{
			i++;
			tmp = tmp->next;
			env_word = ft_split(tmp->content, '=');
		}
		tmp->content = args[1];
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
