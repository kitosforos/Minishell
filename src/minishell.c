/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/02/17 18:00:35 by danicn           ###   ########.fr       */
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
	pid_t	pid;

	flag = 0;
	if (mini->buf == NULL || strcmp(mini->buf, "exit") == 0)
		return ;
	
	args = ft_split2(mini->buf, ' ');
	if (is_pipe_or_redir(args) == 0)
	{
		prepare(args, mini->env);
		if (builtins(args, mini->env) == EXIT_FAILURE)
			exec_process(args, mini->env);
		if (flag == 2)
			exec_process(args, mini->env);
	}
	else{
		prepare(args, mini->env);
		pid = fork();
		if (pid < 0) {
			perror("ERROR\n");
		printf("\n");
			exit(1);
		}
		else if(pid == 0) {
			redirs(args, mini->env);
			exit(0);
		}
		else
			wait(NULL);
	}

}