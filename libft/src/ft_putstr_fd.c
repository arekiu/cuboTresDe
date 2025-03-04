/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:02:52 by aschmidt          #+#    #+#             */
/*   Updated: 2024/04/30 13:33:03 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int	main(void)
{
	char str[] = "chauchi";
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
		ft_putstr_fd(str, fd);
		nr_bytes = read(fd, buf, 10); 
		printf("Number of char: %d, content: %s", (int)nr_bytes, buf);
		close(fd); 
	}
	return (0);
}*/
