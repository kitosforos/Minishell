/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/03/06 22:44:57 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

extern int	g_flagg;

void	read_and_add(t_minishell *mini)
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

int	exitt(t_minishell *mini, char **buf)
{
	int		exit;
	int		i;

	set_to_zero(&i, &exit);
	if (buf[0] && buf[1])
		exit = ft_atoi(buf[1]);
	while (buf[1] && buf[1][i])
	{
		if (ft_isdigit(buf[1][i++]) == 0)
		{
			printf("exit\nexit:%s se requiere un argumento númerico.\n", buf[1]);
			exit = 2;
			exit_free(buf, mini);
			return (exit % 256);
		}
	}
	if (buf[0] && buf[1] && buf[2])
	{
		printf("minishell: exit: demasiados argumentos\n");
		exit = 1;
	}
	exit_free(buf, mini);
	return (exit % 256);
}

int	program_loop(t_minishell *mini)
{	
	char	**buf;

	read_and_add(mini);
	buf = ft_split(mini->buf, ' ');
	while (ft_strncmp(buf[0], "exit", my_select2(buf[0], "exit")))
	{
		if (mini->buf != NULL && ft_strlen(mini->buf)
			&& check_quotes(mini->buf))
			minishell(mini);
		if (g_flagg == -1)
			return (exitt(mini, buf));
		g_flagg = 0;
		free(mini->buf);
		read_and_add(mini);
		split_free(buf);
		buf = ft_split(mini->buf, ' ');
	}
	return (exitt(mini, buf));
}

int	my_select2(char *one, char *two)
{
	if (!one)
		return (4);
	if (ft_strlen(one) > ft_strlen(two))
		return (ft_strlen(one));
	else
		return (ft_strlen(two));
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	int			exit;

	g_flagg = 0;
	errors(argc, argv);
	mini = mini_init(envp);
	if (!mini)
		return (EXIT_FAILURE);
	set_signals();
	exit = program_loop(mini);
	program_free(mini);
	system("leaks minishell");
	return (exit);
}
