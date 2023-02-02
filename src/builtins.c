/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:58:13 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 21:55:22 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtins(char *cmds[], t_env *env)
{
	if (!cmds[0])
		return (EXIT_FAILURE);
	if (strcmp(cmds[0], "echo") == 0)
		my_echo(cmds, env);
	else if (strcmp(cmds[0], "pwd") == 0)
		my_pwd();
	else if (strcmp(cmds[0], "env") == 0)
		my_env(env);
	else if (strcmp(cmds[0], "cd") == 0)
		my_cd(cmds[1]);
	else if (strcmp(cmds[0], "export") == 0)
		my_export(cmds, env);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	dollar_echo(char *argv[], t_env *env, int i)
{
	int		flag;
	char	**words_env;
	char	*var;

	flag = i;
	if (argv[i][1] == '$')
		printf("$");
	var = ft_strtrim(argv[i], "$");
	while (env->env->content)
	{
		words_env = ft_split(env->env->content, '=');
		if (strcmp(words_env[0], var) == 0)
			printf("%s", words_env[1]);
		env->env = env->env->next;
	}
	if (flag == 1)
		printf("\n");
	return (1);
}

int	my_echo(char *argv[], t_env *env)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	if (!argv[1])
	{
		printf("\n");
		return (1);
	}
	if (strcmp(argv[1], "-n") == 0)
		i++;
	if (argv[i][0] == '$')
		return (dollar_echo(argv, env, i));
	while (argv[i])
	{
		if (flag)
			printf(" ");
		printf("%s", argv[i++]);
		flag = 1;
	}
	if (strcmp(argv[1], "-n"))
		printf("\n");
	return (0);
}

int	my_pwd(void)
{
	char	buff[PATH_MAX];

	if (getcwd(buff, sizeof(buff)) != NULL)
		printf("%s\n", buff);
	else
	{
		perror("error in pwd");
		return (0);
	}
	return (1);
}

int	my_env(t_env *env)
{
	int	i;

	i = 0;
	while (env->env->content && env->env->next)
	{
		printf("%s\n", env->env->content);
		env->env = env->env->next;
	}
	printf("%s\n", env->env->content);
	return (1);
}

int	my_cd(char	*argv)
{
	if (chdir(argv) == 0)
		return (1);
	return (0);
}
