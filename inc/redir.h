/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:05:15 by danicn            #+#    #+#             */
/*   Updated: 2023/02/14 16:52:24 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
#define REDIR_H

#include <readline/readline.h>
#include <readline/history.h>
#include "process.h"
#include "libft.h"
#include "env.h"

typedef struct s_redir {
    int     	*pipes;
    int        	n;
    t_list		*cmds;
    t_env		*env;
    int         file;
} t_redir;


int is_pipe_or_redir(char **text);
int	redir_errors(t_redir *red, char **args);
int	pipex(t_redir *red);
int redirs(char **args, t_env *env);
#endif