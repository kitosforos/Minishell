/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:29:27 by danicn            #+#    #+#             */
/*   Updated: 2022/04/01 18:46:48 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd >= 0 && s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

// int main()
// {
// 	char s[] = "Keloke";
// 	int	fd;
// 	fd = open("myfile.txt", O_WRONLY);
// 	ft_putendl_fd(s, fd);
// 	close(fd);
// }