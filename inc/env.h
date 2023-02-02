/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:31 by danicn            #+#    #+#             */
/*   Updated: 2023/02/02 20:02:15 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

typedef struct _Env {
	char	**env;
}Env;

Env	*env_init(char **envp);
void	env_print(Env *env, char *var);
#endif