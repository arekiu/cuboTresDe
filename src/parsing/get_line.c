/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:19:09 by jslusark          #+#    #+#             */
/*   Updated: 2025/03/28 19:20:31 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../cub3d.h"

// #define INT_MAX 42

// char *ft_strdup(char *src)
// {
// 	char *dst;
// 	int len = 0;
// 	int i = 0;
	
// 	while(src[len] != '\0')
// 		len++;
// 	dst = (char *)malloc(sizeof(char) * len + 1); // why (char *)
// 	while(src[i] != '\0')
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return(dst);
// }


char *ft_get_line(int fd)
{
	static char	buff[42];
	char		line[70000];
	static int		buff_read;
	static int		buff_pos;
	int i = 0;
	
	if(fd < 0 || 42 <= 0) // <-------------- FD SHOULD BE < 0 AND NOT <= 0
		return(NULL);
	while(1)
	{
		if(buff_pos >= buff_read)
		{
			buff_read = read(fd, buff, 42);
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

bool	collect_map(int fd, char ***map)
{
	char *line;
	int i = 0;
	*map = malloc(sizeof(char *) * 1024 + 1);
	if (!*map) // and free?
		return (false);

	while(1) // get next line returns the full line until /n
	{
		line = ft_get_line(fd);
		if(line == NULL)
		{
			if(i == 0) // if no lines were read
				return (false);
			break; // else break the loop as no lines left
		}
		(*map)[i] = ft_strdup(line);
		free(line);
		i++;
	}
	(*map)[i] = NULL; // add null terminator to the end of the map
	return(true);
}