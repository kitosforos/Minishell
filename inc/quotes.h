/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:56:54 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/03/06 21:05:18 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

# include <stdlib.h>
# include "libft.h"
# include "env.h"

void	cq_case_one(char *str, int *i, int *count);
void	cq_case_two(char *str, int *i, int *count);
int		check_quotes(char *str);
int		set_flag(char str, int flag, int flag2);
int		my_select2(char *one, char *two);
char	*iq_case_one(char *str, char *word, int *i, int j);
int		set_flag2(int flag2);
void	set_to_zero(int *a, int *b);
char	*free_and_exit(char *str);
char	*iq_procces(char *str, char *word, int flag, int flag2);
char	*ignore_quotes(char *str);
char	*ignore_single_quotes(char *str);
int		prepare(char **str, t_env *env);
int		set_flag3(char str, int flag);
char	*pd_procces(char *str, char *word, t_env *env, char *aux);
char	*prepare_dollar(char	*str, t_env *env, int flag);
int		contains_quotes(char **str);
void	iq_case_two(int *i, char *wd, int *j, char s);

#endif