/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:28:12 by danicn            #+#    #+#             */
/*   Updated: 2023/03/06 22:48:17 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

int	g_flagg;

char	*find_cmd_path(char **path, char *cmd)
{
	char	*cmd_path;
	char	*cmd1;

	if (cmd[0] == '/')
	{
		cmd_path = (char *) malloc(sizeof(char) * (ft_strlen(cmd) + 1));
		if (!cmd_path)
			return (NULL);
		ft_strlcpy(cmd_path, cmd, ft_strlen(cmd) + 1);
		return (cmd_path);
	}
	while (*path)
	{
		cmd1 = ft_strjoin(*path, "/");
		cmd_path = ft_strjoin(cmd1, cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd1);
		free(cmd_path);
		path++;
	}
	return (NULL);
}

char	*find_path(t_env *env)
{
	while (strncmp(env->env->content, "PATH", 4))
	{
		env->env = env->env->next;
	}
	return (env->env->content + 5);
}

void	free_path(char **path, char **arr, char *cmd_path)
{
	while (*path)
	{
		free(*path);
		path++;
	}
	free(path);
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
	free(cmd_path);
}

void	exec_process(char **arr, t_env *env)
{
	int		status;

	if (ft_strncmp(arr[0], env_find(env, "$PATH"), 5) == 0)
	{
		ft_putstr_fd("orden <", STDERR_FILENO);
		ft_putstr_fd(arr[0], STDERR_FILENO);
		ft_putstr_fd("> no encontrada\n", STDERR_FILENO);
	}
	g_flagg = fork();
	if (g_flagg < 0)
		return ;
	else if (g_flagg == 0)
	{
		child_process(arr, env);
		exit(0);
	}
	else
	{
		wait(&status);
		env->exit_status = WEXITSTATUS(status);
		return ;
	}
}

int	child_process(char **arr, t_env *env)
{
	char	**path;
	char	*cmd_path;

	if (!arr || !arr[0])
		return (1);
	desprepare_pipes(arr);
	if (builtins(arr, env) == EXIT_FAILURE)
	{
		path = ft_split(find_path(env), ':');
		if (!path)
			return (1);
		cmd_path = find_cmd_path(path, arr[0]);
		if (!cmd_path)
		{
			put_error_cmd(arr[0]);
			env->exit_status = 127;
			exit(127);
		}
		free(arr[0]);
		arr[0] = cmd_path;
		if (execve(arr[0], arr, env->envp) < 0)
			exit(1);
	}
	return (EXIT_SUCCESS);
}
