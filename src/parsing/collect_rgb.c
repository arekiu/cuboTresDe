/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:15:23 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/22 09:35:24 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
// returns -1 if not valid key
int	store_value(const char *nptr)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	// printf("nptr: '%s'\n", nptr);
	if (!ft_isdigit(nptr[i]))
		return (-2);
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		// to avoid overflow
		if (num > INT_MAX || num < INT_MIN)
			return (-2);
		i++;
	}
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		(i)++;
	if (nptr[i] != '\0')
		return (-2);
	return (num);
}

int	*store_rgb( int *i, char *line)
{
	int		*rgb;
	char	*value;
	int		indexes;
	int		len;

	rgb = malloc(sizeof(int) * 3);
	value = NULL;
	// printf("LINE: %s", line); // C 120,0,16
	indexes = 0;
	// jump the C or F
	(*i)++;
	if (!rgb)
		return (false);
	// loop thorugh the line until is over
	while (line[*i] != 0 && line[*i] != '\n')
	{
		// resets for next value
		len = 0;
		if (indexes > 2)
		{
			free(rgb);	
			return (NULL);
		}
		 //skip spaces
		while (line[*i] == ' ' && line[*i] != '\0')
			(*i)++;
		// if line ends or comma is found we shoot an error
		if (line[*i] == '\0' || line[*i] == ',')
		{
			free(rgb);
			return (NULL);
		}
		// counts value len until
		while (line[*i + len] 
			!= '\0' && line[*i + len] 
			!= '\n' && line[*i + len] 
			!= ',') 
			len++;
		// printf("collected value %d has len %d - from char[%d]:%c to char[%d]: %c,\n", indexes, len, *i, line[*i], (*i)+(len-1), line[(*i)+(len - 1)]);
		value = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(value, line + *i, len + 1);
		// need to use better atoi from philo
		rgb[indexes] = store_value(value);
		free(value);
		*i += len;
		// printf("N %d: %d\n", indexes, rgb[indexes]);
		indexes++;
		// printf("c: '%c'\n", line[*i]); // have a problem with \n at the end for comma edge
		(*i)++;
	}
	// why less than 2
	if (indexes < 2)
	{
		return (NULL);
	}
	else
	{
		// if (line[*i] == '\0')
			// printf("END\n");
		while (line[*i] == ' ' 
			|| line[*i] == '\n' 
			|| line[*i] == '\t') // skip spaces
			(*i)--;
		// printf("----line %s", line);
		// printf("landed on %c | index %d  | indexes %d \n", line[*i], *i, indexes);
		if (line[*i] == ',')
		{
			free(rgb);
			return (NULL);
		}
	}
	return (rgb);
}

bool	collect_rgb(char *line, int *i, t_game *game)
{
	if (match_texture("C ", &game->data->c_found, i, line))
	{
		if (game->data->c_found == 1)
			game->data->C_rgb = store_rgb(i, line);
		return (true);
	}
	if (match_texture("F ", &game->data->f_found, i, line))
	{
		if (game->data->f_found == 1)
			game->data->F_rgb = store_rgb(i, line);
		return (true);
	}
	return (false);
}
