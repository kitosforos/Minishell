/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:36:46 by danicn            #+#    #+#             */
/*   Updated: 2023/01/31 14:16:09 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "process.h"
#include "libft.h"

typedef struct _Minishell {
    char	*buf;
    char	**envp;
} Minishell;

void		mini_free(Minishell *mini);
Minishell	*mini_init(char **envp);
void    	minishell(Minishell *mini);