/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:58:13 by maralons          #+#    #+#             */
/*   Updated: 2023/02/13 20:48:13 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtins(char *cmds[], t_env *env)
{
	int	i;

	i = 0;
	if (!cmds[0])
		return (EXIT_FAILURE);
	if (strcmp(cmds[0], "echo") == 0)
		env->exit_status = my_echo(cmds, env);
	else if (strcmp(cmds[0], "pwd") == 0)
		env->exit_status = my_pwd(cmds);
	else if (strcmp(cmds[0], "env") == 0)
		env->exit_status = my_env(env, cmds);
	else if (strcmp(cmds[0], "cd") == 0)
		env->exit_status = my_cd(cmds[1]);
	else if (strcmp(cmds[0], "export") == 0)
		env->exit_status = my_export(cmds, env);
	else if (ft_strncmp(cmds[0], "unset", ft_strlen(cmds[0])) == 0)
		env->exit_status = my_unset(cmds, env);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	dollar_echo(char *argv[], t_env *env, int i)
{
	int		flag;
	char	**words_env;
	char	*var;
	t_list	*tmp;

	tmp = env->env;
	flag = i;
	if (argv[i][1] == '?')
		printf("%d", env->exit_status);
	var = ft_strtrim(argv[i], "$");
	while (tmp->content && tmp->next && ft_strlen(var))
	{
		words_env = ft_split(tmp->content, '=');
		if (ft_strncmp(words_env[0], var, my_select(words_env[0], var)) == 0)
			printf("%s", words_env[1]);
		tmp = tmp->next;
	}
	words_env = ft_split(tmp->content, '=');
	if (strcmp(words_env[0], var) == 0)
			printf("%s", words_env[1]);
	if (flag == 1)
		printf("\n");
	return (EXIT_SUCCESS);
}

int	my_echo(char *argv[], t_env *env)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 1;
	j = 0;
	if (!argv[1])
	{
		printf("\n");
		return (1);
	}
	if (strcmp(argv[1], "-n") == 0)
		i++;
	while (argv[i])
	{
		if (flag)
			printf(" ");
		j = 0;
		while (argv[i][j])
		{
			printf("%c", argv[i][j++]);
			flag = 1;
		}
		i++;
	}
	if (strcmp(argv[1], "-n"))
		printf("\n");
	return (0);
}

int	my_pwd(char *cmds[])
{
	char	buff[PATH_MAX];

	if (cmds[1])
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	if (getcwd(buff, sizeof(buff)) != NULL)
		printf("%s\n", buff);
	else
	{
		perror("pwd: error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	my_env(t_env *env, char *cmds[])
{
	t_list *tmp;

	if (cmds[1])
	{
		printf("env: too many arguments\n");
		return (EXIT_FAILURE);
	}
	tmp = env->env;
	while (tmp->content && tmp->next)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("%s\n", (char *)tmp->content);
	return (EXIT_SUCCESS);
}
