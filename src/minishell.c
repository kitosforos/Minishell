/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/01/31 21:28:51 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_free(Minishell *mini)
{
	free(mini);
}

Minishell	*mini_init(char **envp)
{
    Minishell	*mini;

	mini = (Minishell *) malloc(sizeof(Minishell));
	if (!mini)
		return (NULL);
	mini->envp = envp;
	mini->buf = NULL;
	return mini;
}

void    minishell(Minishell *mini)
{
    char **args;

    args = ft_split(mini->buf, ' ');
    exec_process(args, mini->envp);
}