/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:42 by danicn            #+#    #+#             */
/*   Updated: 2023/03/02 10:35:54 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "process.h"
# include "env.h"

# define PATH_MAX 32768

int		return_echo(void);
int		my_echo(char *argv[]);
int		my_pwd(char *cmds[]);
int		my_env(t_env *env, char *cmds[]);
int		builtins(char *cmds[], t_env *env);
void	echo_procces(char *argv, int *j, int *flag);
int		my_cd(char	*argv);
int		my_export(char *args[], t_env *env);
int		export_add(char *var, t_env *env);
int		my_unset(char *args[], t_env *env);
int		exp_proc(char *word, char **env_word, t_list *tmp, char *arg);
char	*set_aux(char *word);
char	*get_exp(char *args, int *i);
int		uns_proc(char *args, t_list *tmp, t_list *tmp2, char **env_word);
int		exit_numeric(char *cmds[]);
void	split_free(char **strs);

#endif
