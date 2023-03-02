/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:20:33 by marcos            #+#    #+#             */
/*   Updated: 2023/03/02 15:27:28 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes.h"

void	cq_case_one(char *str, int *i, int *count)
{
	*count = 0;
	*i += 1;
	while (str[*i])
	{
		if (str[*i] == '\"')
		{
			*count = 1;
			break ;
		}
		*i += 1;
	}
}

void	cq_case_two(char *str, int *i, int *count)
{
	*i += 1;
	*count = 0;
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			*count = 1;
			break ;
		}
		*i += 1;
	}
}

int	check_quotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] && count)
	{
		if (str[i] == '\"')
			cq_case_one(str, &i, &count);
		else if (str[i] == '\'')
			cq_case_two(str, &i, &count);
		i++;
	}
	return (count);
}

int	set_flag(char str, int flag, int flag2)
{
	if (str == '\'' && flag == 0 && flag2 == 0)
		flag = 1;
	else if (str == '\'' && flag == 1 && flag2 == 0)
		flag = 0;
	return (flag);
}

char	*iq_case_one(char *str, char *word, int *i, int j)
{
	if (!str[*i + 1])
	{
		word[j] = 0;
		free(str);
		return (word);
	}
	*i += 1;
	return (NULL);
}
