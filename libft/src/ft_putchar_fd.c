/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:49:22 by aschmidt          #+#    #+#             */
/*   Updated: 2024/04/30 13:31:16 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	fd; 
	char	buf[10]; 
	ssize_t nr_bytes; 

	fd = open("test.txt", O_WRONLY);

	if(fd == -1) 
	{
		printf("Error opening the file \n");
	}
	else
	{
		ft_putchar_fd('y', fd);
		nr_bytes = read(fd, buf, 10); 
		printf("Number of char: %d, content: %s", (int)nr_bytes, buf);
		close(fd); 
	}
	return (0);
}*/
