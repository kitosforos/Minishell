/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:58:13 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 22:09:02 by maralons         ###   ########.fr       */
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
	t_list	*tmp;

	tmp = env->env;
	flag = i;
	if (argv[i][1] == '$')
		printf("$");
	var = ft_strtrim(argv[i], "$");
	while (tmp->content && tmp->next)
	{
		words_env = ft_split(tmp->content, '=');
		if (ft_strncmp(words_env[0], var, ft_strlen(var)) == 0)
			printf("%s", words_env[1]);
		tmp = tmp->next;
	}
	words_env = ft_split(tmp->content, '=');
	if (strcmp(words_env[0], var) == 0)
			printf("%s", words_env[1]);
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
	t_list *tmp;

	tmp = env->env;
	while (tmp->content && tmp->next)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("%s\n", (char *)tmp->content);
	return (1);
}
