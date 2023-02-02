/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 19:30:41 by dcruz-na         ###   ########.fr       */
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
	mini->envp = envp;
	mini->buf = NULL;
	return mini;
}

void	minishell(Minishell *mini)
{
	char	**args;

	if (mini->buf == NULL || strcmp(mini->buf, "exit") == 0)
		return ;
	args = ft_split(mini->buf, ' ');
	if (args)
	{
		if (args[0][0] == '$')
			env_print(mini->env, args[0]);
		else if (builtins(args, mini->envp) == EXIT_FAILURE)
			exec_process(args, mini->envp);
	}
}