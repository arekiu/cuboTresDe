/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:30:11 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/07 08:57:05 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	numchar;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			numchar = n + 48;
			write(fd, &numchar, 1);
		}
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd; 
	char	buf[50]; 
	ssize_t nr_bytes; 

	fd = open("test.txt", O_WRONLY); 

	if(fd == -1) 
	{
		printf("Error opening the file \n");
	}
	else
	{
		ft_putnbr_fd(5682, fd);
		nr_bytes = read(fd, buf, 50); 
		printf("Number of char: %d, content: %s", (int)nr_bytes, buf);
		close(fd); 
	}

	return (0);
}*/
