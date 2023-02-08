/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/02/05 12:04:07 by danicn           ###   ########.fr       */
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
	int		flag;

	flag = 0;
	if (mini->buf == NULL || strcmp(mini->buf, "exit") == 0)
		return ;
	args = ft_split(mini->buf, ' ');
	if (is_pipe_or_redir(args) == 0)
	{
		if (args[0][0] == '$')
		{
			flag = env_print(mini->env, args[0] + 1);
			if (flag == 2)
				args = ft_split(ft_itoa(mini->env->exit_status), ' ');
		}
		else if (builtins(args, mini->env) == EXIT_FAILURE)
			exec_process(args, mini->env);
		if (flag == 2)
			exec_process(args, mini->env);
	}
	else{
		redirs(args, mini->env);
	}
}