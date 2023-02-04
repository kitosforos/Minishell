/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 21:53:30 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	read_and_add(Minishell *mini)
{
	mini->buf = readline("Minishell > ");
	if (mini->buf != NULL)
		add_history(mini->buf);
}

void	errors(int argc, char **argv)
{
	if (argc != 1 || !(*argv))
		exit(EXIT_FAILURE);
}

void	program_loop(Minishell *mini)
{
	signal(SIGINT, SIG_IGN);
	read_and_add(mini);
	while (ft_strncmp(mini->buf, "exit", ft_strlen(mini->buf) + 1) != 0)
	{
		if (mini->buf != NULL && ft_strlen(mini->buf))
		{
			minishell(mini);
			free(mini->buf);
		}
		read_and_add(mini);
	}
	printf("Exit\n");
	free(mini->buf);
}

void	program_free(Minishell *mini)
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
