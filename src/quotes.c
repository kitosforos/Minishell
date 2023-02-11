#include "quotes.h"

int	check_quotes(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == '\"')
			count++;
	}
	return (count % 2);
}

char	*ignore_quotes(char *str)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (ft_strlen(str) - 1));
	if (str[i] == '\"')
		i++;
	else
		return (str);
	while (str[i])
	{
		if (str[i] == '\"')
		{
			word[i - 1] = 0;
			return (word);
		}
		word[i - 1] = str[i];
		i++;
	}
	return (word);
}