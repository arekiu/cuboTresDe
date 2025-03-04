/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:12:20 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/21 11:28:10 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_check_left_over(char *left_over, int fd);
static char	*_set_line(int fd, char *buff, char *temp_line);
static char	*_set_left_over(char *line);
static char	*_clean_line(char *line);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_over[FOPEN_MAX];

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = _check_left_over(left_over[fd], fd);
	if (!line)
	{
		free (left_over[fd]);
		left_over[fd] = NULL;
		return (NULL);
	}
	left_over[fd] = _set_left_over(line);
	line = _clean_line(line);
	if (!line)
	{
		free (left_over[fd]);
		left_over[fd] = NULL;
		return (NULL);
	}
	return (line);
}

static char	*_check_left_over(char *left_over, int fd)
{
	char	*buff;
	char	*combined_line;

	if (left_over != NULL && ft_strchr(left_over, '\n'))
		return (left_over);
	else
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		combined_line = _set_line(fd, buff, left_over);
		free (buff);
		buff = NULL;
		if (!combined_line)
			return (NULL);
	}
	return (combined_line);
}

static char	*_set_line(int fd, char *buff, char *temp_line)
{
	ssize_t	nr_bytes;
	char	*temp;

	nr_bytes = 1;
	while (nr_bytes > 0)
	{
		nr_bytes = read(fd, buff, BUFFER_SIZE);
		if (nr_bytes == -1)
			return (NULL);
		if (nr_bytes == 0)
			break ;
		buff[nr_bytes] = '\0';
		if (!temp_line)
			temp_line = ft_strdup("");
		if (!temp_line)
			return (NULL);
		temp = temp_line;
		temp_line = ft_strjoin(temp, buff);
		free (temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (temp_line);
}

static char	*_set_left_over(char *line)
{
	int		i;
	char	*left_over;

	i = 0;
	if (ft_strchr(line, '\n'))
	{
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		if (line[i] == '\n')
			i++;
		if (line[i] == '\0')
			return (NULL);
		left_over = ft_substr(line, i, ft_strlen(line));
		if (!left_over)
			return (NULL);
		return (left_over);
	}
	else
		return (NULL);
}

static char	*_clean_line(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	temp = line;
	line = ft_substr(temp, 0, i);
	free (temp);
	temp = NULL;
	if (!line)
		return (NULL);
	return (line);
}
