/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:28:23 by maralons          #+#    #+#             */
/*   Updated: 2023/02/24 15:01:11 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins2.h"

int	my_cd(char *argv)
{
	char	*path;
	char	buff[PATH_MAX];

	path = ft_strjoin(getcwd(buff, sizeof(buff)), "/");
	path = ft_strjoin(path, argv);
	if (chdir(argv) == -1)
	{
		if (access(path, F_OK) == -1)
			printf("cd: no existe el archivo o directorio: %s\n", argv);
		else
			printf("cd: permiso denegado: %s\n", argv);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

char	*get_exp(char *args, int *i)
{
	char	**words;

	words = ft_split(args, '=');
	printf("%s\n", words[0]);
	while (words[0][*i])
	{
		if (ft_isalnum(words[0][*i]) == 0 && words[0][*i] != '_')
			return (NULL);
		*i += 1;
	}
	if (!words[1])
		return (EXIT_SUCCESS);
	return (words[0]);
}

char	*set_aux(char *word, char *args)
{
	char	*aux;

	aux = malloc(sizeof(char) * (ft_strlen(args) + 1));
	if (!aux)
		return (NULL);
	aux = ft_strjoin("", "$");
	aux = ft_strjoin(aux, word);
	return (aux);
}

int	exp_proc(char *word, char **env_word, t_list *tmp, char *arg)
{
	while (ft_strncmp(word, env_word[0], ft_strlen(env_word[0])) != 0)
	{
		tmp = tmp->next;
		env_word = ft_split(tmp->content, '=');
	}
	tmp->content = arg;
	return (EXIT_SUCCESS);
}

int	my_export(char *args[], t_env *env)
{
	char	*word;
	char	**env_word;
	t_list	*tmp;
	char	*aux;
	int		i;

	i = 0;
	if (args[1][0] >= 48 && args[1][0] <= 57)
		return (exit_numeric(args));
	tmp = env->env;
	word = get_exp(args[1], &i);
	if (!word)
		return (exit_numeric(args));
	aux = set_aux(word, args[1]);
	env_word = ft_split(tmp->content, '=');
	if (ft_strncmp(env_find(env, aux), "", 1) != 0)
		exp_proc(word, env_word, tmp, args[1]);
	else
		export_add(args[1], env);
	return (EXIT_SUCCESS);
}
