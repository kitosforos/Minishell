/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:03:08 by danicn            #+#    #+#             */
/*   Updated: 2022/04/01 20:41:36 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	declar(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

static void	init(char *s, int *j, int *k, char c)
{
	while ((char)(s[*j]) == c)
		*k = ++(*j);
	while ((char)(s[*j]) != c && s[*j])
		(*j)++;
}

static int	allocate(char **s, int i, int j, int k)
{
	s[i] = (char *)malloc(sizeof(char) * (j - k + 1));
	if (s[i] == NULL)
	{
		while (--i >= 0)
			free(s[i]);
		free(s);
		return (0);
	}
	return (1);
}

static int	counting_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		z;
	int		k;
	char	**sts;

	if (s == NULL)
		return (NULL);
	sts = (char **) malloc(sizeof(char *) * (counting_words(s, c) + 1));
	if (sts == NULL)
		return (NULL);
	declar(&i, &j, &k);
	while (i < counting_words(s, c))
	{
		init((char *)s, &j, &k, c);
		if (allocate(sts, i, j, k) == 0)
			return (NULL);
		z = 0;
		while (k < j)
			sts[i][z++] = (char)(s[k++]);
		sts[i++][z] = 0;
	}
	sts[i] = NULL;
	return ((char **)sts);
}
// int main(){
// 	int i;
// 	char x[] = "   lorem   ipsum dolor     sit amet, co
// 	char **strs = ft_split(x, ' ');
// 	i = 0;
// 	while(strs[i])
// 		printf("%s\n", strs[i++]);
// 	printf("%s", strs[i]);
// 	system("leaks a.out");
// }
