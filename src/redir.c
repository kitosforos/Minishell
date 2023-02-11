/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:05:09 by danicn            #+#    #+#             */
/*   Updated: 2023/02/11 13:00:08 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir.h"

char **take_cmd(t_list *lst)
{
	char **cmd;
	int	i;
	t_list *l;
	
	i = 0;
	l = lst;
	
	while (l && ft_strncmp(l->content, "|", 1) != 0)
	{
		i++;
		l = l->next;
	}
	cmd = (char **) malloc(sizeof(char *)*(i+1));
	if (!cmd)
		return (NULL);
	i = 0;
	l = lst;
	while (l && l->content && ft_strncmp(l->content, "|", 1) 
		&& ft_strncmp(l->content, ">", 1) && ft_strncmp(l->content, "<", 1))
	{
		cmd[i] = (char *) malloc(sizeof(char)*(ft_strlen(l->content)+1));
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

int	redir_errors(t_redir *red, char **args)
{
	if (!red || !args)
		return (EXIT_FAILURE);
	// pipex(red, args);
	return (0);
}
int redirs(char **args, t_env *env)
{
	t_redir *red;
	
	red = redir_init(args, env);
	if (redir_errors(red, args) == EXIT_FAILURE)
	{
		printf("error\n");
		return (EXIT_FAILURE);
	}
	pipex(red);
	return (EXIT_SUCCESS);
}


int redirection(t_redir *red, t_list *lst) {
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
		red->file = open(lst->next->next->content, O_RDONLY);
		dup2(red->file, 0);
	}
	return (0);
}

int	pipex(t_redir *red)
{
	int	i;
	int j;
	pid_t	pds;
	t_list	*lst;
	char	**str;
	
	i = 0;
	lst = red->cmds;
	while(lst)
	{
		pds = fork();
		if( pds == 0 ) {
			
			/* child gets input from the previous command,
				if it's not the first command */
			if(lst != red->cmds)
			{
				if( dup2(red->pipes[(i-1)*2], 0) < 0)
				{
					perror("ERRORx\n");
					exit(1);
				}
			}
			if (ft_strncmp(lst->content, "<", 1) == 0)
			{
				red->file = open(lst->next->content, O_RDONLY);
				dup2(red->file, 0);
				lst = lst->next->next;
			}
			/* child outputs to next command, if it's not
				the last command */
			if(i != red->n){
				if( dup2(red->pipes[i*2+1], 1) < 0 ) {
					perror("ERRORy\n");
					exit(1);
				}
			}
			for( j = 0; j < 2 * red->n; j++ ){
				close(red->pipes[j]);
			}
			str = take_cmd(lst);
			redirection(red, lst);
			child_process(str, red->env);
			exit(0);
		}
		else if( pds < 0)
		{
			perror("ERRORz\n");
			exit(1);
		}
		while (lst && ft_strncmp(lst->content, "|", 1) != 0) {
			lst = lst->next;
		}
		if (lst && ft_strncmp(lst->content, "|", 1) == 0)
			lst = lst->next;
		i++;
	}
	wait(NULL);
	/* parent closes all of its copies at the end */
	for( i = 0; i < 2 * red->n; i++ ){
		close(red->pipes[i]);
	}
	return (EXIT_SUCCESS);
}
