/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:34 by maralons          #+#    #+#             */
/*   Updated: 2023/02/05 12:05:23 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
#include "minishell.h"
#include "quotes.h"
#include "process.h"
#include "libft.h"
#include "env.h"
#include "signals.h"

extern int g_signal;


void	errors(int argc, char **argv);
void	program_loop(Minishell *mini);
void	program_free(Minishell *mini);

#endif