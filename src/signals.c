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

void    signals()
{
    signal(SIGINT, ctrlc);
	signal(SIGQUIT, ctrld);
}

void	ctrld(int n)
{
	n = n;
	exit(1);
}
void	ctrlc(int n)
{
	n=n;
	exit(1);
}
