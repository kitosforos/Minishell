/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:32:24 by danicn            #+#    #+#             */
/*   Updated: 2023/02/03 19:59:07 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int g_signal;

void	set_signals(void)
{
	signal(SIGINT, ctrlc);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrlc(int n)
{
	n += 1;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
