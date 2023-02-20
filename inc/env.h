/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:31 by danicn            #+#    #+#             */
/*   Updated: 2023/02/20 12:12:35 by danicn           ###   ########.fr       */
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

void		env_free(t_env *env);
t_env		*env_init(char **envp);
int			env_print(t_env *env, char *var);
char		*env_find(t_env *env, char *var);
#endif