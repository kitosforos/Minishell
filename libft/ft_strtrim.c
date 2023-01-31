/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:57:01 by danicn            #+#    #+#             */
/*   Updated: 2022/04/01 18:28:55 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	beginning_count(char *s, char *set)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	while (s[i])
	{
		f = 0;
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				f = 1;
			j++;
		}
		if (f)
			i++;
		else
			break ;
	}
	return (i);
}

static int	final_count(char *s, char *set)
{
	int	i;
	int	j;
	int	f;

	i = (int) ft_strlen(s) - 1;
	while (i >= 0)
	{
		f = 0;
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				f = 1;
			j++;
		}
		if (f)
			i--;
		else
			break ;
	}
	return ((int)ft_strlen(s) - i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		b;
	int		f;
	char	*str;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	b = beginning_count((char *)s1, (char *)set);
	f = final_count((char *)s1, (char *) set);
	i = (int)ft_strlen(s1) - b - f + 1;
	if (b >= (int) ft_strlen(s1) - f)
		return (ft_strdup(""));
	str = (char *) malloc(sizeof(char) * (i));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (b < (int)(ft_strlen(s1) - f))
		str[i++] = s1[b++];
	str[i] = 0;
	return (str);
}

// int main(){
// 	char s[] = "zzxzxzzxzhxolaxzxzxfzxxz", set[] = "zx";
// 	printf("%s", ft_strtrim(s, set));
// }