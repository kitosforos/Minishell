/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:07:21 by danicn            #+#    #+#             */
/*   Updated: 2023/03/01 12:08:48 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "quotes.h"
# include "libft.h"
# include "env.h"
# include "builtins.h"

void	exec_process(char **arr, t_env *env);
void	free_path(char **path, char **arr, char *cmd_path);
char	*find_path(t_env *env);
char	*find_cmd_path(char **path, char *cmd);
int		child_process(char **arr, t_env *env);
void	desprepare_pipes(char **args);

#endif
