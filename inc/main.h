/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:34 by maralons          #+#    #+#             */
/*   Updated: 2023/03/02 10:43:53 by maralons         ###   ########.fr       */
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
void	read_and_add(t_minishell *mini);
int		exitt(t_minishell *mini, char **buf);
int		my_select2(char *one, char *two);
#endif