/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:28:12 by danicn            #+#    #+#             */
/*   Updated: 2023/01/31 14:24:49 by danicn           ###   ########.fr       */
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

char	*find_path(char **envp)
{
	while (strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
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

void	exec_process(char **arr, char **envp)
{
    
	pid_t	parent;
	
	parent = fork();
	if (parent < 0) 
	{
		return ;
	}
	else if (parent == 0)
	{
		child_process(arr, envp);
	}
	else
	{
		wait(NULL);
		return ;
	}
}

void	child_process(char **arr, char **envp)
{
	char	**path;
	char	*cmd_path;
	
	path = ft_split(find_path(envp), ':');
	cmd_path = find_cmd_path(path, arr[0]);
	if (!cmd_path)
	{
		free_path(path, arr, cmd_path);
		return ;
	}
	free(arr[0]);
	arr[0] = cmd_path;
	execve(arr[0], arr, envp);
	free_path(path, arr, cmd_path);
}