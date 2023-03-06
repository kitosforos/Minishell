/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:32:24 by danicn            #+#    #+#             */
/*   Updated: 2023/03/03 21:53:08 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

extern int	g_flagg;

void	set_signals(void)
{
	signal(SIGINT, ctrlc);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrlc(int n)
{
	n += 1;
	if (g_flagg)
	{
		printf("\n");
		kill(g_flagg, n);
		return ;
	}
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
