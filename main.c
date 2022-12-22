/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:40 by maralons          #+#    #+#             */
/*   Updated: 2022/12/22 19:35:19 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"	

int	main()
{
	char	*buffer;

	while (strcmp(buffer, "EXIT") != 0)
	{
		buffer = readline("Minishell > ");
		add_history(buffer);
		printf("%s\n", buffer);
	}
	rl_clear_history();
	system("leaks a.out");
	return (0);
}