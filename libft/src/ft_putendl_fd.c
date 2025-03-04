/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:10:51 by aschmidt          #+#    #+#             */
/*   Updated: 2024/04/30 13:56:22 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	char str[] = "nos vimo";
	int	fd; 
	char	buf[10]; 
	ssize_t nr_bytes; 

	fd = open("test1.txt", O_WRONLY); 

	if(fd == -1) 
	{
		printf("Error opening the file \n");
	}
	else
	{
		ft_putendl_fd(str, fd);
		nr_bytes = read(fd, buf, 10); 
		printf("Number of char: %d, content: %s", (int)nr_bytes, buf);
		close(fd); 
	}
	return (0);
}*/
