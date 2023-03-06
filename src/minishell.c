/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/03/06 23:16:19 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	piping_process(char **args, t_minishell *mini)
{
	pid_t	pid;
	int		err;

	err = 0;
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

void	mini_free(t_minishell *mini)
{
	if (mini)
	{
		env_free(mini->env);
		free(mini);
	}
}

t_minishell	*mini_init(char **envp)
{
	t_minishell	*mini;

	mini = (t_minishell *) malloc(sizeof(t_minishell));
	if (!mini)
		return (NULL);
	mini->env = env_init(envp);
	if (!mini->env)
		return (NULL);
	mini->buf = NULL;
	return (mini);
}

void	prepare_pipes(char *buf)
{
	int	i;
	int	flag;
	int	flag2;

	i = 0;
	flag = 0;
	flag2 = 0;
	while (buf[i])
	{
		if (buf[i] == '\'' && (!flag2 && !flag))
			flag = 1;
		else if (buf[i] == '\'' && flag)
			flag = 0;
		if (buf[i] == '\"' && (!flag && !flag2))
			flag2 = 1;
		else if (buf[i] == '\"' && flag2)
			flag2 = 0;
		if ((flag2 || flag) && buf[i] == '|')
			buf[i] = 17;
		if ((flag2 || flag) && buf[i] == '<')
			buf[i] = 18;
		if ((flag2 || flag) && buf[i] == '>')
			buf[i] = 19;
		i++;
	}
}

int	minishell(t_minishell *mini)
{
	char	**args;

	if (mini->buf == NULL)
		return (EXIT_FAILURE);
	prepare_pipes(mini->buf);
	args = ft_split2(mini->buf, ' ');
	if (prepare(args, mini->env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_pipe_or_redir(args) == 0)
	{
		desprepare_pipes(args);
		if (ft_strncmp(args[0], "echo", my_select2(args[0], "echo")) == 0)
			mini->env->exit_status = my_echo(args, mini);
		else if (builtins(args, mini->env) == EXIT_FAILURE)
			exec_process(args, mini->env);
	}
	else
		piping_process(args, mini);
	split_free(args);
	return (EXIT_SUCCESS);
}
