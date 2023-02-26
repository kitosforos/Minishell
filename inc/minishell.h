/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:36:46 by danicn            #+#    #+#             */
/*   Updated: 2023/02/25 17:58:57 by dcruz-na         ###   ########.fr       */
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

typedef struct _Minishell {
	char		*buf;
	t_env		*env;
}	Minishell;

void		mini_free(Minishell *mini);
Minishell	*mini_init(char **envp);
int			minishell(Minishell *mini);
char		**ft_split2(char const *s, char c);
void		split_free(char **strs);
#endif