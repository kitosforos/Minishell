/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:18:17 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/03/02 00:17:27 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir.h"

int	red_input(t_redir *red, t_list *lst)
{
	int		err;

	err = 0;
	if (ft_strlen(lst->next->content) == 1)
	{
		red->file = open(lst->next->next->content, O_RDONLY);
		if (red->file < 0)
			return (EXIT_FAILURE);
		err = dup2(red->file, 0);
		if (err < 0)
			return (EXIT_FAILURE);
	}
	else if (ft_strlen(lst->next->content) == 2
		&& ft_strncmp(lst->next->content, "<<", 2) == 0)
		err = red_input_get(red, lst);
	return (err);
}

int	redirection(t_redir *red, t_list *lst)
{
	int	err;

	err = 0;
	while (lst->next && ft_strncmp(lst->next->content, "|", 1) != 0
		&& ft_strncmp(lst->next->content, ">", 1) != 0
		&& ft_strncmp(lst->next->content, "<", 1) != 0)
		lst = lst->next;
	if (lst->next && ft_strncmp(lst->next->content, ">", 1) == 0)
		err = red_output(lst, red);
	else if (lst->next && ft_strncmp(lst->next->content, "<", 1) == 0)
		err = red_input(red, lst);
	return (err);
}

int	input_output(t_redir *red, t_list **lst, int i)
{
	if (*lst != red->cmds)
		if (dup2(red->pipes[(i - 1) * 2], 0) < 0)
			return (1);
	if (ft_strncmp((*lst)->content, "<", 1) == 0)
	{
		red->file = open((*lst)->next->content, O_RDONLY);
		if (red->file < 0)
			return (1);
		if (dup2(red->file, 0) < 0)
			return (1);
		*lst = (*lst)->next->next;
	}
	if (i != red->n)
		if (dup2(red->pipes[i * 2 + 1], 1) < 0)
			return (1);
	return (0);
}

int	pipex_child(t_redir *red, t_list **lst, int i, int j)
{
	pid_t	pds;
	char	**str;

	pds = fork();
	if (pds > 0)
	{
		close(red->pipes[j]);
		wait(NULL);
	}
	else if (pds == 0)
	{
		if (input_output(red, lst, i) < 0)
			return (1);
		i = 0;
		while (i < 2 * red->n)
			close(red->pipes[i++]);
		str = take_cmd(*lst);
		if (!str)
			return (1);
		redirection(red, *lst);
		child_process(str, red->env);
	}
	else if (pds < 0)
		return (1);
	return (0);
}

int	pipex(t_redir *red)
{
	int		i;
	int		j;
	t_list	*lst;

	j = 1;
	i = 0;
	lst = red->cmds;
	while (lst)
	{
		if (pipex_child(red, &lst, i, j) == -1)
			return (1);
		while (lst && ft_strncmp(lst->content, "|", 1) != 0)
			lst = lst->next;
		if (lst && ft_strncmp(lst->content, "|", 1) == 0)
			lst = lst->next;
		i++;
		j += 2;
	}
	wait(NULL);
	i = 0;
	while (i < 2 * red->n)
		close(red->pipes[i++]);
	return (EXIT_SUCCESS);
}
