/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/02/20 12:25:21 by danicn           ###   ########.fr       */
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

int exitt(Minishell *mini)
{
	char	**buf;
	int		exit;
	int		i;
	
	i = 0;
	exit = 0;
	buf = ft_split(mini->buf, ' ');
	if (buf[0] && buf[1])
		exit = ft_atoi(buf[1]);
	while (buf[1] && buf[1][i])
	{
		if (ft_isdigit(buf[1][i++]) == 0)
		{
			write(1, "exit\n", 5);
			write(1, "minishell: exit: ", 17);
			write(1, buf[1], ft_strlen(buf[1]));
			write(1, " se requiere un argumento numérico\n", 36);
			split_free(buf);
			free(mini->buf);
			return (2);
		}
	}
	write(1, "exit\n", 5);
	if (buf[0] && buf[1] && buf[2])
	{
		write(1, "minishell: exit: demasiados argumentos\n", 39);
		exit = 1;
	}
	split_free(buf);
	free(mini->buf);
	clear_history();
	return (exit % 256);
}

int	program_loop(Minishell *mini)
{	
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
	return (exitt(mini));	
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
