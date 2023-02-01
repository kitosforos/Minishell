/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/02/01 21:25:34 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "main.h"

void	read_and_add(Minishell *mini)
{
	mini->buf = readline("Minishell > ");
	add_history(mini->buf);
;}

void	errors(int argc, char **argv)
{
	if (argc != 1 || !(*argv))
		exit(EXIT_FAILURE);
}

void	program_loop(Minishell *mini)
{
	signal(SIGINT, SIG_IGN);
	read_and_add(mini);
	while (strncmp(mini->buf, "exit", 4) != 0)
	{
		minishell(mini);
		free(mini->buf);
		read_and_add(mini);
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