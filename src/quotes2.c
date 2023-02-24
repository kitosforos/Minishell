/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:31:47 by marcos            #+#    #+#             */
/*   Updated: 2023/02/24 11:45:19 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes.h"

int	set_flag2(int flag2)
{
	if (flag2 == 0)
		flag2 = 1;
	else
		flag2 = 0;
	return (flag2);
}

void	set_to_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

char	*free_and_exit(char *str)
{
	free(str);
	return (NULL);
}

char	*iq_procces(char *str, char *word, int flag, int flag2)
{
	int		i;
	int		j;
	char	*aux;

	set_to_zero(&i, &j);
	while (str[i])
	{
		flag = set_flag(str[i], flag, flag2);
		if (str[i] == '\"' && flag == 0)
		{
			aux = iq_case_one(str, word, &i, j);
			if (aux)
				return (aux);
			flag2 = set_flag2(flag2);
		}
		else
		{
			if (str[i] == '\'' && flag2 == 1)
				word[j++] = '\'';
			word[j++] = str[i++];
		}
	}
	word[j] = 0;
	free(str);
	return (word);
}

char	*ignore_quotes(char *str)
{
	char	*word;
	int		flag;
	int		flag2;

	set_to_zero(&flag, &flag2);
	word = malloc(sizeof(char) * 10000000);
	if (!word)
		free_and_exit(str);
	return (iq_procces(str, word, flag, flag2));
}
