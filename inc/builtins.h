/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:42 by danicn            #+#    #+#             */
/*   Updated: 2023/01/31 20:47:54 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

#define PATH_MAX 32768

int	dollar_echo(char *argv[], char *envp[], int i);
int	my_echo(char *argv[], char *envp[]);
int	my_pwd(void);
int	my_env(char *envp[]);
int	my_cd(char	*argv);
