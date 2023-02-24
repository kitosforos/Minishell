/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:29:36 by maralons          #+#    #+#             */
/*   Updated: 2023/02/24 15:02:27 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS2_H
# define BUILTINS2_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "env.h"
# include "libft.h"

# define PATH_MAX 32768

int		my_cd(char	*argv);
int		my_export(char *args[], t_env *env);
int		export_add(char *var, t_env *env);
int		my_unset(char *args[], t_env *env);
int		exp_proc(char *word, char **env_word, t_list *tmp, char *arg);
char	*set_aux(char *word, char *args);
char	*get_exp(char *args, int *i);
int		uns_proc(char *args, t_list *tmp, t_list *tmp2, char **env_word);
int		exit_numeric(char *cmds[]);

#endif