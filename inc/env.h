/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:31 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 21:53:42 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

typedef struct _Env {
	t_list		*env;
	char		**envp;
	int			exit_status;
}	t_env;

t_env		*env_init(char **envp);
int			env_print(t_env *env, char *var);
char		*env_find(t_env *env, char *var);
int	my_select(char *one, char *two);
#endif