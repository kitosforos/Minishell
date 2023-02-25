/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:18:12 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/02/25 17:54:04 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir.h"

int	redir_check_errors(t_list **l)
{
	if (ft_strncmp("|", (*l)->content, 1) == 0)
	{
		*l = (*l)->next;
		if (*l && ft_strncmp("|", (*l)->content, 1) == 0)
			return (1);
	}
	if (ft_strlen((*l)->content) == 2 && !ft_strncmp(">>", (*l)->content, 2))
	{
		*l = (*l)->next;
		if (*l && (ft_strncmp(">", (*l)->content, 1) == 0
				|| !ft_strncmp("<", (*l)->content, 1)
				|| !ft_strncmp("|", (*l)->content, 1)))
			return (1);
	}
	if (*l && ft_strlen((*l)->content) == 2
		&& (ft_strncmp("<<", (*l)->content, 2) == 0
			|| ft_strncmp("|", (*l)->content, 1) == 0))
	{
		*l = (*l)->next;
		if (*l && (!ft_strncmp(">", (*l)->content, 1)
				|| !ft_strncmp("<", (*l)->content, 1)
				|| !ft_strncmp("|", (*l)->content, 1)))
			return (1);
	}
	return (0);
}

int	redir_errors(t_redir *red, char **args)
{
	t_list	*lst;
	int		err;

	if (!red || !args)
		return (EXIT_FAILURE);
	err = 0;
	lst = red->cmds;
	while (lst)
	{
		err = redir_check_errors(&lst);
		if (err == 1)
			break ;
		lst = lst->next;
	}
	return (err);
}

int	redirs(char **args, t_env *env)
{
	t_redir	*red;
	int		err;

	err = 0;
	red = redir_init(args, env);
	if (red && redir_errors(red, args) == EXIT_FAILURE)
	{
		redir_destroy(red);
		printf("minishell: error sintáctico\n");
		return (EXIT_FAILURE);
	}
	if (red)
		err = pipex(red);
	redir_destroy(red);
	return (err);
}

int	red_output(t_list *lst, t_redir *red)
{
	int	err;

	err = 0;
	if (ft_strlen(lst->next->content) == 1)
		red->file = open((char *)lst->next->next->content, O_WRONLY
				| O_CREAT | O_TRUNC, S_IRWXU);
	else if (ft_strlen(lst->next->content) == 2
		&& ft_strncmp(lst->next->content, ">>", 2) == 0)
		red->file = open((char *)lst->next->next->content, O_WRONLY
				| O_APPEND | O_CREAT, S_IRWXU);
	if (red->file == -1)
		return (EXIT_FAILURE);
	err = dup2(red->file, 1);
	if (err < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	red_input_get(t_redir *red, t_list *lst)
{
	char	*buffer;
	int		err;

	red->file = open(".auxiliar", O_WRONLY | O_CREAT, S_IRWXU);
	if (red->file < 0)
		return (EXIT_FAILURE);
	buffer = readline("> ");
	while (strncmp(buffer, lst->next->next->content, ft_strlen(buffer)) != 0)
	{
		write(red->file, buffer, ft_strlen(buffer));
		write(red->file, "\n", 1);
		free(buffer);
		buffer = readline("> ");
	}
	close(red->file);
	red->file = open(".auxiliar", O_RDONLY);
	if (red->file < 0)
		return (EXIT_FAILURE);
	err = dup2(red->file, 0);
	if (err < 0)
		return (EXIT_FAILURE);
	unlink(".auxiliar");
	return (EXIT_SUCCESS);
}
