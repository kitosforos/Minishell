/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:13:08 by maralons          #+#    #+#             */
/*   Updated: 2023/03/06 23:14:09 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_procces(char *argv, int *k, char *buf)
{
	int	j;

	j = 0;
	while (argv[j])
	{	
		printf("%c", argv[j]);
		j += 1;
		*k += 1;
	}
	if (buf[*k] == ' ')
	{
		printf(" ");
		*k += 1;
	}
}

int	my_echo(char *argv[], t_minishell *mini)
{
	int	i;
	int	flag;
	int	k;

	mini->buf = prepare_dollar(mini->buf, mini->env, 0);
	k = 5;
	flag = 0;
	i = 1;
	if (!argv[1])
		return (return_echo());
	if (ft_strncmp(argv[1], "-n", 2) == 0)
	{
		i++;
		k += 3;
	}
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
