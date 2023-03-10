/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:31:45 by marcos            #+#    #+#             */
/*   Updated: 2023/03/06 22:26:27 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quotes.h"

char	*ignore_single_quotes(char *str)
{
	int		i;
	char	*word;
	char	*aux;
	int		j;

	set_to_zero(&i, &j);
	word = malloc(sizeof(char) * 100000000);
	if (!word)
		free_and_exit(str);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			aux = iq_case_one(str, word, &i, j);
			if (aux)
				return (aux);
		}
		else if (str[i] == 17)
			iq_case_two(&i, word, &j, '\'');
		else
			word[j++] = str[i++];
	}
	word[j] = 0;
	free(str);
	return (word);
}

int	prepare(char **str, t_env *env)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ignore_quotes(str[i]);
		if (str[i] == NULL)
			return (1);
		str[i] = prepare_dollar(str[i], env, 0);
		if (str[i] == NULL)
			return (1);
		str[i] = ignore_single_quotes(str[i]);
		if (str[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}

int	set_flag3(char str, int flag)
{
	if (str == '\'' && flag == 0)
		flag = 1;
	else if (str == '\'' && flag == 1)
		flag = 0;
	return (flag);
}

char	*pd_procces(char *str, char *word, t_env *env, char *aux)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	set_to_zero(&i, &j);
	while (str && str[i])
	{
		flag = set_flag3(str[i], flag);
		if (str[i] == '$' && flag == 0)
		{	
			ft_strlcpy(aux, env_find(env, str + i),
				ft_strlen(env_find(env, str + i)) + 1);
			ft_strlcpy(word + strlen(word), aux, ft_strlen(aux) + 1);
			j += ft_strlen(aux);
			i++;
			while (str[i] && str[i] != ' ' && str[i] != '$'
				&& (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
		}
		else
			word[j++] = str[i++];
	}
	word[j] = 0;
	return (word);
}

char	*prepare_dollar(char *str, t_env *env, int flag)
{
	char	*word;
	char	*aux;

	word = ft_calloc(10000000, sizeof(char));
	if (!word)
		return (NULL);
	aux = malloc(sizeof(char) * 100000000);
	if (!aux)
		return (NULL);
	if (ft_strncmp(str, "$?", my_select2(str, "$?")) == 0)
	{
		free(aux);
		free(word);
		free(str);
		return (ft_itoa(env->exit_status));
	}
	word = pd_procces(str, word, env, aux);
	if (!flag)
	{
		free(aux);
		free(str);
	}
	return (word);
}
