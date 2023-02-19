/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/02/13 21:01:03 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	read_and_add(Minishell *mini)
{
	mini->buf = readline("Minishell > ");
	if (mini->buf != NULL)
		add_history(mini->buf);
	else
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
}

void	errors(int argc, char **argv)
{
	if (argc != 1 || !(*argv))
		exit(EXIT_FAILURE);
}

int	program_loop(Minishell *mini)
{
	int	exit;
	int	i;

	i = 5;
	read_and_add(mini);
	while (ft_strncmp(mini->buf, "exit", 4))
	{
		if (mini->buf != NULL && ft_strlen(mini->buf) && check_quotes(mini->buf))
		{
			minishell(mini);
			free(mini->buf);
		}
		read_and_add(mini);
	}
	exit = ft_atoi(mini->buf + 5);
	while (mini->buf[i])
	{
		if (ft_isalpha(mini->buf[i++]))
			exit = 255;
	}
	printf("exit\n");
	free(mini->buf);
	return (exit % 256);
}

void	program_free(Minishell *mini)
{
	mini_free(mini);
}


int	main(int argc, char **argv, char **envp)
{
	Minishell	*mini;
	int			exit;

	errors(argc, argv);
	mini = mini_init(envp);
	if (!mini)
		return (EXIT_FAILURE);
	set_signals();
	exit = program_loop(mini);
	program_free(mini);
	return (exit);
}
