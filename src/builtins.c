/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:58:13 by maralons          #+#    #+#             */
/*   Updated: 2023/03/06 23:14:17 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

extern int	g_flagg;

int	builtins(char *cmds[], t_env *env)
{
	if (!cmds[0])
		return (EXIT_FAILURE);
	if (!cmds[0][0])
		return (EXIT_SUCCESS);
	else if (ft_strncmp(cmds[0], "pwd", my_select2("pwd", cmds[0])) == 0)
		env->exit_status = my_pwd(cmds);
	else if (ft_strncmp(cmds[0], "env", my_select2("env", cmds[0])) == 0)
		env->exit_status = my_env(env, cmds);
	else if (ft_strncmp(cmds[0], "cd", my_select2("cd", cmds[0])) == 0)
		env->exit_status = my_cd(cmds[1]);
	else if (ft_strncmp(cmds[0], "export", my_select2("export", cmds[0])) == 0)
		env->exit_status = my_export(cmds, env);
	else if (ft_strncmp(cmds[0], "unset", my_select2("unset", cmds[0])) == 0)
		env->exit_status = my_unset(cmds, env);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
