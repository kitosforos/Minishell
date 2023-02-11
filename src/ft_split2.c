/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:53:59 by danicn            #+#    #+#             */
/*   Updated: 2023/02/11 14:59:29 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	declar(int *i, int *j, int *k);
static void	init(char *s, int *j, int *k, char c);
static int	allocate(char **s, int i, int j, int k);
static int	counting_words(const char *str, char c);

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
    if (s[(*j)] == '|' || s[(*j)] == '<' || s[(*j)] == '>')
    {
        if ((s[(*j)] == '<' && s[(*j) + 1] == '<') || (s[(*j)] == '>' && s[(*j) + 1] == '>'))
            (*j)++;
        (*j)++;
        return ;
    }        
	while ((char)(s[*j]) != c && s[*j] && s[*j] != '|' && s[*j] != '<' && s[*j] != '>') {
		(*j)++;
    }
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
        if (*str == '|' || *str == '<' || *str == '>')
        {
            if ((*str == '<' && *(str + 1) == '<') || (*str == '>' && *(str + 1) == '>'))
                str++;
            trigger = 0;
            i++;
        }
		else if (*str != c && trigger == 0)
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

char	**ft_split2(char const *s, char c)
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

// int main(int argc, char **argv)
// {
//     char *x = " hola>>que  |>>tal|archivo.txt <";
//     char **split;
//     int i=0;
    
//     split = ft_split2(x, ' ');
//     while (split[i]) {
//         printf("%d: %s\n", i, split[i]);
//         i++;
//     }
//     printf("%d: %s\n", i, split[i]);
// }