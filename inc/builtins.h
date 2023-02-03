/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:42 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 21:28:53 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "builtins2.h"
# include "env.h"

# define PATH_MAX 32768

int	dollar_echo(char *argv[], t_env *env, int i);
int	my_echo(char *argv[], t_env *env);
int	my_pwd(void);
int	my_env(t_env *env);
int	builtins(char *cmds[], t_env *env);

#endif
