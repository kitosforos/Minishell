/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:58:13 by maralons          #+#    #+#             */
/*   Updated: 2023/02/24 14:03:51 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtins(char *cmds[], t_env *env)
{
	if (!cmds[0])
		return (EXIT_FAILURE);
	if (strcmp(cmds[0], "echo") == 0)
		env->exit_status = my_echo(cmds);
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

int	return_echo(void)
{
	printf("\n");
	return (1);
}

int	my_echo(char *argv[])
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 1;
	j = 0;
	if (!argv[1])
		return (return_echo());
	if (strcmp(argv[1], "-n") == 0)
		i++;
	while (argv[i])
	{
		echo_procces(argv[i], &j, &flag);
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
	t_list	*tmp;

	if (cmds[1])
	{
		printf("env: too many arguments\n");
		return (EXIT_FAILURE);
	}
	tmp = env->env;
	while (tmp->next)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	if (tmp->content)
		printf("%s\n", (char *)tmp->content);
	return (EXIT_SUCCESS);
}
