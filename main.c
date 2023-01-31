/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2023/01/31 13:43:13 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	minishell_loop(char *envp[])
{
	char	*buffer;
	char	**cmds;

	buffer = readline("Minishell > ");
	while (strcmp(buffer, "exit") != 0)
	{
		add_history(buffer);
		cmds = ft_split(buffer, ' ');
		if (builtins(cmds, envp) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		buffer = readline("\nMinishell > ");
	}
	return (EXIT_SUCCESS);
}

void	minishell_free(void)
{
	rl_clear_history();
}

int	main(int argc, char *argv[], char *envp[])
{
	if (minishell_loop(envp) == 1)
	{		
		minishell_free();
		return (EXIT_FAILURE);
	}
	minishell_free();
	return (EXIT_SUCCESS);
}