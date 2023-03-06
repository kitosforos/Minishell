/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:36:46 by danicn            #+#    #+#             */
/*   Updated: 2023/03/06 23:20:59 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <locale.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "process.h"
# include "builtins.h"
# include "env.h"
# include "libft.h"
# include "redir.h"

typedef struct s_minishell {
	char		*buf;
	t_env		*env;
}	t_minishell;

void		piping_process(char **args, t_minishell *mini);
void		echo_procces(char *argv, int *k, char *buf);
int			my_echo(char *argv[], t_minishell *mini);
void		mini_free(t_minishell *mini);
t_minishell	*mini_init(char **envp);
int			minishell(t_minishell *mini);
char		**ft_split2(char const *s, char c);
void		split_free(char **strs);
void		prepare_pipes(char *buf);
void		exit_free(char **buf, t_minishell *mini);
void		return_echo(void);
#endif