/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:58:13 by maralons          #+#    #+#             */
/*   Updated: 2023/01/31 20:46:24 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	dollar_echo(char *argv[], char *envp[], int i)
{
	int		flag;
	char	**words_env;
	char	*var;

	flag = i;
	if (argv[i][1] == '$')
		printf("$");
	var = ft_strtrim(argv[i], "$");
	while (envp[i])
	{
		words_env = ft_split(envp[i++], '=');
		if (strcmp(words_env[0], var) == 0)
			printf("%s", words_env[1]);
	}
	if (flag == 1)
		printf("\n");
	return (1);
}

int	my_echo(char *argv[], char *envp[])
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	if (!argv[1])
	{
		printf("\n");
		return (1);
	}
	if (strcmp(argv[1], "-n") == 0)
		i++;
	if (argv[i][0] == '$')
		return (dollar_echo(argv, envp, i));
	while (argv[i])
	{
		if (flag)
			printf(" ");
		printf("%s", argv[i++]);
		flag = 1;
	}
	if (strcmp(argv[1], "-n"))
		printf("\n");
	return (0);
}

int	my_pwd(void)
{
	char	buff[PATH_MAX];

	if (getcwd(buff, sizeof(buff)) != NULL)
		printf("%s\n", buff);
	else
	{
		perror("error in pwd");
		return (0);
	}
	return (1);
}

int	my_env(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
	return (1);
}

int	my_cd(char	*argv)
{
	if (chdir(argv) == 0)
		return (1);
	return (0);
}