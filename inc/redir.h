/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:05:15 by danicn            #+#    #+#             */
/*   Updated: 2023/02/25 17:35:06 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include <readline/readline.h>
# include <readline/history.h>
# include "process.h"
# include "libft.h"
# include "env.h"

typedef struct s_redir {
	int			*pipes;
	int			n;
	t_list		*cmds;
	t_env		*env;
	int			file;
}	t_redir;

int		is_pipe_or_redir(char **text);
int		redir_errors(t_redir *red, char **args);
int		pipex(t_redir *red);
int		redirs(char **args, t_env *env);
int		red_input(t_redir *red, t_list *lst);
int		redir_check_errors(t_list **l);
int		redir_errors(t_redir *red, char **args);
int		red_output(t_list *lst, t_redir *red);
int		red_input_get(t_redir *red, t_list *lst);
void	redir_destroy(t_redir *red);
char	**take_cmd(t_list *lst);
int		redir_lst(char **args, t_redir *red);
t_redir	*redir_init(char **args, t_env *env);
int		redirection(t_redir *red, t_list *lst);
int		input_output(t_redir *red, t_list **lst, int i);
int		pipex_child(t_redir *red, t_list **lst, int i);

#endif