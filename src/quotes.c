#include "quotes.h"

int	check_quotes(char	*str)
{
	int	i;
	int	count;
	int	count2;

	i = 0;
	count = 0;
	count2 = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			count++;
		else if (str[i] == '\'')
			count2++;
		i++;
	}
	return ((count % 2) + (count2 % 2));
}

char	*ignore_quotes(char *str)
{
	int		i;
	char	*word;
	int		j;

	i = 0;
	j = 0;
	word = malloc(sizeof(char) * (ft_strlen(str) - 1));
	while (str[i] != '\"' && str[i])
		word[j++] = str[i++];
	if (!str[i])
		return (str);
	while (str[i])
	{
		if (str[i] == '\"')
		{
			if (!str[i + 1])
			{
				word[i - 1] = 0;
				return (word);
			}
			i++;
		}
		word[j++] = str[i++];
	}
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
	word = malloc(sizeof(char) * (ft_strlen(str) - 1));
	while (str[i] != '\'' && str[i])
		word[j++] = str[i++];
	if (!str[i])
		return (str);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (!str[i + 1])
			{
				word[i - 1] = 0;
				return (word);
			}
			i++;
		}
		word[j++] = str[i++];
	}
	word[j] = 0;
	return (word);
}