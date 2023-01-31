/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:34 by maralons          #+#    #+#             */
/*   Updated: 2023/01/31 20:45:49 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "process.h"
#include "builtins.h"
#include "libft.h"

void	errors(int argc, char **argv);
void	program_loop(Minishell *mini);
void	program_free(Minishell *mini);
