/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:19:09 by jslusark          #+#    #+#             */
/*   Updated: 2025/03/28 19:20:31 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 42

char *ft_strdup(char *src)
{
	char *dst;
	int len = 0;
	int i = 0;
	
	while(src[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * len + 1); // why (char *)
	while(src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return(dst);
}


char *gnl(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		line[70000];
	static int		buff_read;
	static int		buff_pos;
	int i = 0;
	
	if(fd < 0 || BUFFER_SIZE <= 0) // <-------------- FD SHOULD BE < 0 AND NOT <= 0
		return(NULL);
	while(1)
	{
		if(buff_pos >= buff_read)
		{
			buff_read = read(fd, buff, BUFFER_SIZE);
			buff_pos = 0;
			if(buff_read <= 0)
				break;
		}
		if(buff[buff_pos] == '\n')
		{
			line[i++] = buff[buff_pos++]; // <------ THIS WAS I DID NOT ADD :(((
			break;
		}
		line[i] = buff[buff_pos++];
		i++;
	}
	if(i == 0)
		return(NULL);
	line[i] = '\0';
	return(ft_strdup(line));
}

// int main(void)
// {
// 	int fd = open("./txt.txt", O_RDONLY);
// 	//printf("%s", gnl(fd));
// 	char *line;
// 	while((line = gnl(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 	}
// 	/*int fd = open("./txt.txt", O_RDONLY);
// 	printf("%s", gnl(fd));
// 	return(0);*/
// }