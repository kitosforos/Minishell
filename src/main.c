/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/02/01 14:29:03 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "main.h"

int	builtins(char *cmds[], char *envp[])
{
	if (!cmds[0])
		return (EXIT_FAILURE);
	if (strcmp(cmds[0], "echo") == 0)
		my_echo(cmds, envp);
	else if (strcmp(cmds[0], "pwd") == 0)
		my_pwd();
	else if (strcmp(cmds[0], "env") == 0)
		my_env(envp);
	else if (strcmp(cmds[0], "cd") == 0)
		my_cd(cmds[1]);
	return (EXIT_SUCCESS);
}

void	errors(int argc, char **argv)
{
	if (argc != 1 || !(*argv))
		exit(EXIT_FAILURE);
}

void	program_loop(Minishell *mini)
{
	signal(SIGINT, SIG_IGN);
	mini->buf = readline("Minishell > ");
	if (!mini->buf)
		return ;
	while (strcmp(mini->buf, "exit") != 0)
	{
		printf("%s\n", mini->buf);
		add_history(mini->buf);
		minishell(mini);
		free(mini->buf);
		mini->buf = readline("Minishell > ");
	}
	free(mini->buf);
}

void program_free(Minishell *mini)
{
	mini_free(mini);
}

int	main(int argc, char **argv, char **envp)
{
	Minishell	*mini;
	
	errors(argc, argv);
	mini = mini_init(envp);
	if (!mini)
		return (EXIT_FAILURE);
	program_loop(mini);
	program_free(mini);
	return (0);
}