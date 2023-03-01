/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:32:24 by danicn            #+#    #+#             */
/*   Updated: 2023/03/02 00:20:29 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int flagg;

void	set_signals(void)
{
	signal(SIGINT, ctrlc);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrlc(int n)
{
	n += 1;
	flagg = 0;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
