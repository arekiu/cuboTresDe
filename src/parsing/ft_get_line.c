/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:53:22 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/20 17:15:54 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	read_next(int fd, char *buff, int *buff_read, int *buff_pos)
{
	if (*buff_pos >= *buff_read)
	{
		*buff_read = read(fd, buff, 42);
		*buff_pos = 0;
		if (*buff_read <= 0)
			return (false);
	}
	return (true);
}

char	*ft_get_line(int fd)
{
	static char		buff[42];
	char			line[70000];
	static int		buff_read;
	static int		buff_pos;
	int				i;

	i = 0;
	if (fd < 0 || 42 <= 0)
		return (NULL);
	while (1)
	{
		if (!read_next(fd, buff, &buff_read, &buff_pos))
			break ;
		if (buff[buff_pos] == '\n')
		{
			line[i++] = buff[buff_pos++];
			break ;
		}
		line[i] = buff[buff_pos++];
		i++;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}
