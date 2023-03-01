/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:05:09 by danicn            #+#    #+#             */
/*   Updated: 2023/03/01 19:24:36 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir.h"

void	redir_destroy(t_redir *red)
{
	t_list	*lst;

	free(red->pipes);
	while (red->cmds)
	{
		lst = red->cmds->next;
		free(red->cmds);
		red->cmds = lst;
	}
	free(red);
}

char	**take_cmd(t_list *lst)
{
	char	**cmd;
	int		i;
	t_list	*l;

	i = 0;
	l = lst;
	while (l && ft_strncmp(l->content, "|", 1) != 0 && i++ > -1)
		l = l->next;
	cmd = (char **) malloc(sizeof(char *) * (i + 1));
	if (!cmd)
		return (NULL);
	i = 0;
	l = lst;
	while (l && l->content && ft_strncmp(l->content, "|", 1)
		&& ft_strncmp(l->content, ">", 1) && ft_strncmp(l->content, "<", 1))
	{
		cmd[i] = (char *) malloc(sizeof(char) * (ft_strlen(l->content) + 1));
		if (!cmd[i])
			return (NULL);
		ft_strlcpy(cmd[i++], l->content, ft_strlen(l->content) + 1);
		l = l->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	redir_lst(char **args, t_redir *red)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (args[i][0] == '|')
		{
			ft_lstadd_back(&red->cmds, ft_lstnew(args[i]));
			red->n++;
		}
		else
			ft_lstadd_back(&red->cmds, ft_lstnew(args[i]));
		i++;
	}
	red->pipes = (int *) malloc(sizeof(int) * red->n * 2);
	if (!red->pipes)
		return (1);
	i = 0;
	while (i < red->n)
	{
		if (pipe(red->pipes + i * 2) < 0)
			return (1);
		i++;
	}
	return (0);
}

t_redir	*redir_init(char **args, t_env *env)
{
	t_redir	*red;

	red = (t_redir *) malloc(sizeof(t_redir));
	if (!red)
		return (NULL);
	red->env = env;
	red->n = 0;
	red->cmds = ft_lstnew(args[0]);
	if (!red->cmds)
		return (NULL);
	if (redir_lst(args, red) == EXIT_FAILURE)
		return (NULL);
	return (red);
}

int	is_pipe_or_redir(char **text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i][0] == '|' || text[i][0] == '>' || text[i][0] == '<')
			return (1);
		i++;
	}
	return (0);
}
