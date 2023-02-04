/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:34 by maralons          #+#    #+#             */
/*   Updated: 2023/02/02 21:21:35 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
#include "minishell.h"
#include "process.h"
#include "libft.h"
#include "env.h"

void	errors(int argc, char **argv);
void	program_loop(Minishell *mini);
void	program_free(Minishell *mini);

#endif