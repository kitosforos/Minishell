/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:05:09 by danicn            #+#    #+#             */
/*   Updated: 2023/02/22 16:39:37 by danicn           ###   ########.fr       */
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

char **take_cmd(t_list *lst)
{
	char **cmd;
	int	i;
	t_list *l;
	
	i = 0;
	l = lst;
	while (l && ft_strncmp(l->content, "|", 1) != 0 && i++ > -1)
		l = l->next;
	cmd = (char **) malloc(sizeof(char *)*(i+1));
	if (!cmd)
		return (NULL);
	i = 0;
	l = lst;
	while (l && l->content && ft_strncmp(l->content, "|", 1) 
		&& ft_strncmp(l->content, ">", 1) && ft_strncmp(l->content, "<", 1))
	{
		cmd[i] = (char *) malloc(sizeof(char)*(ft_strlen(l->content)+1));
		if (!cmd[i])
			return (NULL);
		ft_strlcpy(cmd[i++], l->content, ft_strlen(l->content)+1);
		l = l->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

t_redir	*redir_init(char **args, t_env *env)
{
	t_redir *red;
	int	i;
	
	red = (t_redir *) malloc(sizeof(t_redir));
	if (!red)
		return (NULL);
	red->env = env;
	red->n = 0;
	i = 1;
	red->cmds = ft_lstnew(args[0]);
	if (!red->cmds)
		return (NULL);
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
	red->pipes = (int *) malloc(sizeof(int)*red->n*2);
	if (!red->pipes)
		return (NULL);
	/* parent creates all needed pipes at the start */
	for ( i = 0; i < red->n; i++ ){
		if( pipe(red->pipes + i*2) < 0 )
		{
			perror("Error");
			exit(1);
		}
	}
	return red;
}

int is_pipe_or_redir(char **text)
{
    int i;
    
    i = 0;
    while (text[i])
    {
        if (text[i][0] == '|' || text[i][0] == '>' || text[i][0] == '<')
            return (1);
        i++;
    }
    return (0);
}

// int	pipex(t_redir *red, char **args)
// {
// 	if (!red || !args)
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

int	redir_check_errors(t_list **lst)
{
	if (ft_strncmp("|", (*lst)->content, 1) == 0)
	{
		*lst = (*lst)->next;
		if (*lst && ft_strncmp("|", (*lst)->content, 1) == 0)
			return (1);
	}
	if (*lst && ft_strlen((*lst)->content) == 2 && ft_strncmp(">>", (*lst)->content, 2) == 0)
	{
		*lst = (*lst)->next;
		if (*lst && (ft_strncmp(">", (*lst)->content, 1) == 0 
			|| ft_strncmp("<", (*lst)->content, 1) == 0 || ft_strncmp("|", (*lst)->content, 1) == 0))
			return (1);
	}
	if (*lst && ft_strlen((*lst)->content) == 2 
		&& (ft_strncmp("<<", (*lst)->content, 2) == 0 || ft_strncmp("|", (*lst)->content, 1) == 0))
	{
		*lst = (*lst)->next;
		if (*lst && (ft_strncmp(">", (*lst)->content, 1) == 0 
			|| ft_strncmp("<", (*lst)->content, 1) == 0 || ft_strncmp("|", (*lst)->content, 1) == 0))
			return (1);
	}
	return (0);
}

int	redir_errors(t_redir *red, char **args)
{
	t_list *lst;
	int 	err;
	
	if (!red || !args)
		return (EXIT_FAILURE);
	err = 0;
	lst = red->cmds;
	while (lst)
	{
		err = redir_check_errors(&lst);
		if (err == 1)
			break;
		lst = lst->next;
	}
	return (err);
}

int redirs(char **args, t_env *env)
{
	t_redir	*red;
	int		err;

	err = 0;
	red = redir_init(args, env);
	if (red && redir_errors(red, args) == EXIT_FAILURE)
	{
		printf("minishell: error sintáctico\n");
		return (EXIT_FAILURE);
	}
	if (red)
		err = pipex(red);
	redir_destroy(red);
	return (err);
}


int redirection(t_redir *red, t_list *lst) {
	char *buffer;
	
	while (lst->next && ft_strncmp(lst->next->content, "|", 1) != 0 && ft_strncmp(lst->next->content, ">", 1) != 0 && ft_strncmp(lst->next->content, "<", 1) != 0)
		lst = lst->next;
	if (lst->next && ft_strncmp(lst->next->content, ">", 1) == 0)
	{
		if (ft_strlen(lst->next->content) == 1)
			red->file = open((char *)lst->next->next->content, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		else if (ft_strlen(lst->next->content) == 2 && ft_strncmp(lst->next->content, ">>", 2) == 0)
			red->file = open((char *)lst->next->next->content, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		if (red->file == -1) {
			perror("ERROR: \n");
			exit(1);
		}
		//fprintf(stderr, "%s\n", (char *)lst->next->next->content);
		dup2(red->file, 1);
	}
	else if(lst->next && ft_strncmp(lst->next->content, "<", 1) == 0)
	{
		if (ft_strlen(lst->next->content) == 1)
		{
			red->file = open(lst->next->next->content, O_RDONLY);
			if (red->file < 0)
				return (EXIT_FAILURE);
			dup2(red->file, 0);
		}
		else if (ft_strlen(lst->next->content) == 2 && ft_strncmp(lst->next->content, "<<", 2) == 0)
		{
			red->file = open(".auxiliar", O_WRONLY | O_CREAT, S_IRWXU);
			if (red->file < 0)
			{
				printf("ERROR in file");
				exit(1);
			}
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
			dup2(red->file, 0);
			unlink(".auxiliar");
		}
	}
	return (0);
}

int	input_output(t_redir *red, t_list **lst, int i)
{
	if(*lst != red->cmds)
		if( dup2(red->pipes[(i-1)*2], 0) < 0)
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
		if( dup2(red->pipes[i*2+1], 1) < 0 )
			return(1);
	return (0);
}

int	pipex_child(t_redir *red, t_list **lst, int i)
{
	pid_t	pds;
	char	**str;

	pds = fork();
	if( pds == 0 )
	{
		if (input_output(red, lst, i) < 0)
			return (1);
		for( i = 0; i < 2 * red->n; i++)
			close(red->pipes[i]);
		str = take_cmd(*lst);
		if (!str)
			return (1);
		redirection(red, *lst);
		child_process(str, red->env);
	}
	else if(pds < 0)
		return (1);
	return (0);
}

int	pipex(t_redir *red)
{
	int	i;
	t_list	*lst;
	
	i = 0;
	lst = red->cmds;
	while(lst)
	{
		if (pipex_child(red, &lst, i) == -1)
			return (1);
		while (lst && ft_strncmp(lst->content, "|", 1) != 0)
			lst = lst->next;
		if (lst && ft_strncmp(lst->content, "|", 1) == 0)
			lst = lst->next;
		i++;
	}
	wait(NULL);
	for( i = 0; i < 2 * red->n; i++ )
		close(red->pipes[i]);
	return (EXIT_SUCCESS);
}
