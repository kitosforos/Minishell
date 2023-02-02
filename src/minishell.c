/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 21:48:17 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_free(Minishell *mini)
{
	free(mini);
}

Minishell	*mini_init(char **envp)
{
	Minishell	*mini;

	mini = (Minishell *) malloc(sizeof(Minishell));
	if (!mini)
		return (NULL);
	mini->env = env_init(envp);
	if (!mini->env)
		return NULL;
	mini->buf = NULL;
	return (mini);
}

void	minishell(Minishell *mini)
{
	char	**args;

	if (mini->buf == NULL || strcmp(mini->buf, "exit") == 0)
		return ;
	args = ft_split(mini->buf, ' ');
	if (args[0][0] == '$')
		env_print(mini->env, args[0]);
	else if (builtins(args, mini->env) == EXIT_FAILURE)
		exec_process(args, mini->env);
}