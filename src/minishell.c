/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/02/24 16:27:16 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	piping_process(char **args, Minishell *mini)
{
	pid_t	pid;
	int		err;

	err = 0;
	prepare(args, mini->env);
	pid = fork();
	if (pid < 0)
	{
		perror("ERROR\n");
		printf("\n");
		split_free(args);
		exit(1);
	}
	else if (pid == 0)
	{
		err = redirs(args, mini->env);
		split_free(args);
		exit(err);
	}
	else
		wait(NULL);
}

void	mini_free(Minishell *mini)
{
	if (mini)
	{
		env_free(mini->env);
		free(mini);
	}
}

Minishell	*mini_init(char **envp)
{
	Minishell	*mini;

	mini = (Minishell *) malloc(sizeof(Minishell));
	if (!mini)
		return (NULL);
	mini->env = env_init(envp);
	if (!mini->env)
		return (NULL);
	mini->buf = NULL;
	return (mini);
}

int	minishell(Minishell *mini)
{
	char	**args;

	if (mini->buf == NULL)
		return (EXIT_FAILURE);
	args = ft_split2(mini->buf, ' ');
	if (is_pipe_or_redir(args) == 0)
	{
		if (prepare(args, mini->env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (builtins(args, mini->env) == EXIT_FAILURE)
			exec_process(args, mini->env);
	}
	else
		piping_process(args, mini);
	// split_free(args);
	return (EXIT_SUCCESS);
}
