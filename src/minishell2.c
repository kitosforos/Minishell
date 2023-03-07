/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:13:08 by maralons          #+#    #+#             */
/*   Updated: 2023/03/07 01:09:45 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_procces(char *argv, int *k, char *buf)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	if (buf[*k] == '\'' || buf[*k] == '\"')
	{
		flag = 1;
		*k += 1;
	}
	while (argv[j])
	{	
		printf("%c", argv[j]);
		j += 1;
		*k += 1;
	}
	if (flag)
		*k += 1;
	if (buf[*k] == ' ')
	{
		*k += 1;
		while (buf[*k] == ' ')
			*k += 1;
		printf(" ");
	}
}

int	my_echo(char *argv[], t_minishell *mini)
{
	int	i;
	int	k;

	mini->buf = prepare_dollar(mini->buf, mini->env, 0);
	k = 5;
	i = 1;
	if (!argv[1])
		return (return_echo());
	if (ft_strncmp(argv[1], "-n", 2) == 0)
	{
		i++;
		k += 3;
	}
	while (mini->buf[k] == ' ')
		k++;
	while (argv[i])
	{
		echo_procces(argv[i], &k, mini->buf);
		i++;
	}
	if (ft_strncmp(argv[1], "-n", 2))
		printf("\n");
	return (0);
}

int	return_echo(void)
{
	printf("\n");
	return (1);
}
