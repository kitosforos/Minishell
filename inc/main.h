/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:34 by maralons          #+#    #+#             */
/*   Updated: 2023/02/13 20:50:35 by maralons         ###   ########.fr       */
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

void	errors(int argc, char **argv);
int		program_loop(Minishell *mini);
void	program_free(Minishell *mini);

#endif