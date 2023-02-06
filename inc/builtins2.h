/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:29:36 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 21:51:31 by maralons         ###   ########.fr       */
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

int	my_cd(char	*argv);
int	my_export(char *args[], t_env *env);
int	export_add(char *var, t_env *env);
int	my_unset(char *args[], t_env *env);
int	my_select(char *one, char *two);
int	exit_numeric(char *cmds[]);

#endif