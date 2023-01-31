/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:07:21 by danicn            #+#    #+#             */
/*   Updated: 2023/01/31 14:25:30 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

void	exec_process(char **arr, char **envp);
void	free_path(char **path, char **arr, char *cmd_path);
char	*find_path(char **envp);
char	*find_cmd_path(char **path, char *cmd);
void	child_process(char **arr, char **envp);



