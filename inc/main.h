/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:34 by maralons          #+#    #+#             */
/*   Updated: 2023/02/25 17:54:34 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
# include "minishell.h"
# include "quotes.h"
# include "process.h"
# include "libft.h"
# include "env.h"
# include "signals.h"

void	errors(int argc, char **argv);
int		program_loop(t_minishell *mini);
void	program_free(t_minishell *mini);
void	split_free(char **strs);
int		my_select2(char *one, char *two);
#endif