/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:11 by danicn            #+#    #+#             */
/*   Updated: 2023/01/31 14:17:31 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_free(Minishell *mini)
{
	free(mini);
	if (mini->buf)
		free(mini->buf);
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