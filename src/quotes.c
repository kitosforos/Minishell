#include "quotes.h"

int	check_quotes(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			count = 0;
			i++;
			while (str[i])
			{
				if (str[i] == '\"')
				{
					count = 1;
					break ;
				}
				i++;
			}
		}
		else if (str[i] == '\'')
		{
			i++;
			count = 0;
			while (str[i])
			{
				if (str[i] == '\'')
				{
					count = 1;
					break ;
				}
				i++;
			}
		}
		i++;
	}
	return (count);
}

char	*ignore_quotes(char *str, t_env *env)
{
	int		i;
	char	*word;
	char	*aux;
	int		flag;
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	word = malloc(sizeof(char) * 10000000);
	aux = malloc(sizeof(char) * 10000000);
	while (str[i])
	{
		if (str[i] == '\"')
		{
			if (flag == 1)
				flag = 0;
			else
				flag = 1;
			if (!str[i + 1])
			{
				word[j] = 0;
				return (word);
			}
			i++;
		}
		// if (flag == 1 && str[i] == '$')
		// {
		// 	ft_strlcpy(aux, env_find(env, str + i), ft_strlen(env_find(env, str + i)) + 1);
		// 	printf("%s\n\n\n\n\n\n", aux);
		// 	word = ft_strjoin(word, aux);
		// 	j += ft_strlen(aux) + 5;
		// }
		word[j++] = str[i++];
	}
	free(aux);
	word[j] = 0;
	return (word);
}

char	*ignore_single_quotes(char *str)
{
	int		i;
	char	*word;
	int		j;

	i = 0;
	j = 0;
	word = malloc(sizeof(char) * 100000000);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (!str[i + 1])
			{
				word[j] = 0;
				return (word);
			}
			i++;
		}
		word[j++] = str[i++];
	}
	word[j] = 0;
	return (word);
}

int	prepare(char **str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = prepare_dollar(str[i], env);
		str[i] = ignore_quotes(str[i], env);
		str[i] = ignore_single_quotes(str[i]);
		i++;
	}
	i = 0;
}

char	*prepare_dollar(char	*str, t_env *env)
{
	int		i;
	char	*word;
	char	*aux;
	int		flag;
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	word = malloc(sizeof(char) * 10000000);
	aux = malloc(sizeof(char) * 10000000);
	while (str[i])
	{
		if (str[i] == '\'' && flag == 0)
			flag = 1;
		else if (str[i] == '\'' && flag == 1)
			flag = 0;
		if (str[i] == '$' && flag == 0)
		{
			ft_strlcpy(aux, env_find(env, str + i), ft_strlen(env_find(env, str + i)) + 1);
			word = ft_strjoin(word, aux);
			j += ft_strlen(aux);
			while (str[i] && str[i] != ' ')
				i++;
		}
		word[j++] = str[i++];
	}
	word[j] = 0;
	return (word);
}

int	contains_quotes(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\"')
				return (1);
			else if (str[i][j] == '\'')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}