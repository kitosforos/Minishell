/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:28:12 by danicn            #+#    #+#             */
/*   Updated: 2023/02/05 13:59:04 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

char	*find_cmd_path(char **path, char *cmd)
{
	char	*cmd_path;
	char	*cmd1;

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
	pid_t	parent;
	int		status;

	parent = fork();
	if (parent < 0) 
		return ;
	else if (parent == 0)
	{
		child_process(arr, env);
		exit(0);
	}
	else
	{
		wait(&status);
		exit_status = WEXITSTATUS(status);
		return ;
	}
}

int	child_process(char **arr, t_env *env)
{
	char	**path;
	char	*cmd_path;

	if (!arr || !arr[0])
		return (1);
	path = ft_split(find_path(env), ':');
	if (!path)
	{
		return (1);
	}
	cmd_path = find_cmd_path(path, arr[0]);
	if (!cmd_path)
	{
		printf("orden <<%s>> no encontrada\n", arr[0]);
		exit_status = 127;
		exit(127);
	}
	free(arr[0]);
	arr[0] = cmd_path;
	execve(arr[0], arr, env->envp);
	return (EXIT_SUCCESS);
}
