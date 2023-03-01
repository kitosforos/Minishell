/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:28:23 by maralons          #+#    #+#             */
/*   Updated: 2023/03/01 18:42:07 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	char	*word;

	words = ft_split(args, '=');
	while (words[0][*i])
	{
		if (ft_isalnum(words[0][*i]) == 0 && words[0][*i] != '_')
			return (NULL);
		*i += 1;
	}
	if (!words[1])
	{
		split_free(words);
		return (EXIT_SUCCESS);
	}
	word = (char *) malloc(sizeof(words[0]));
	ft_strlcpy(word, words[0], ft_strlen(words[0]) + 1);
	split_free(words);
	return (word);
}

char	*set_aux(char *word)
{
	char	*aux;
	char	*x;

	aux = ft_strjoin("", "$");
	x = aux;
	aux = ft_strjoin(aux, word);
	free(x);
	return (aux);
}

int	exp_proc(char *word, char **env_word, t_list *tmp, char *arg)
{
	while (ft_strncmp(word, env_word[0], ft_strlen(env_word[0])) != 0)
	{
		tmp = tmp->next;
		env_word = ft_split(tmp->content, '=');
	}
	ft_strlcpy(tmp->content, arg, ft_strlen(arg) + 1);
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
	aux = set_aux(word);
	env_word = ft_split(tmp->content, '=');
	if (ft_strncmp(env_find(env, aux), "", 1) != 0)
		exp_proc(word, env_word, tmp, args[1]);
	else
		export_add(args[1], env);
	free(aux);
	split_free(env_word);
	free(word);
	return (EXIT_SUCCESS);
}
