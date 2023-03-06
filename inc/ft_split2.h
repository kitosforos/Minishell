/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:12:18 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/03/06 21:46:43 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT2_H
# define FT_SPLIT2_H

# include <stdio.h>
# include <stdlib.h>

void	declar(int *i, int *j, int *k);
void	init(char *s, int *j, int *k, char c);
int		allocate(char **s, int i, int j, int k);
int		counting_words(const char *str, char c);
void	comillas(char **str, int *i, int *x, int *trigger);
char	**ft_split2(char const *s, char c);
int		init2(char *s, int *j, int *k, char c);
#endif