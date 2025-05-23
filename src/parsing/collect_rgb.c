/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:15:23 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 18:06:35 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	store_value(const char *nptr)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	if (!ft_isdigit(nptr[i]))
		return (-2);
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
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

bool	get_rgb_value(char *line, int *i, int *rgb, int *rgb_n)
{
	int		len;
	char	*value;

	value = NULL;
	len = 0;
	while (line[*i] == ' ' && line[*i] != '\0')
		(*i)++;
	if (line[*i] == '\0' || line[*i] == ',')
	{
		free(rgb);
		return (false);
	}
	while (line[*i + len] 
		!= '\0' && line[*i + len] 
		!= '\n' && line[*i + len] 
		!= ',') 
		len++;
	value = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(value, line + *i, len + 1);
	rgb[(*rgb_n)] = store_value(value);
	free(value);
	*i += len;
	(*rgb_n)++;
	return (true);
}

bool	rgb_n_are_correct(int rgb_n, char *line, int *i, int *rgb)
{
	if (rgb_n < 3)
	{
		free(rgb);
		return (false);
	}
	while (line[*i] == ' ' 
		|| line[*i] == '\n' 
		|| line[*i] == '\t')
		(*i)--;
	if (line[*i] == ',')
	{
		free(rgb);
		return (false);
	}
	return (true);
}

int	*store_rgb( int *i, char *line)
{
	int		*rgb;
	int		rgb_n;

	rgb = malloc(sizeof(int) * 3);
	rgb_n = 0;
	(*i)++;
	if (!rgb)
		return (false);
	while (line[*i] != 0 && line[*i] != '\n')
	{
		if (rgb_n > 2)
		{
			free(rgb);
			return (NULL);
		}
		if (!get_rgb_value(line, i, rgb, &rgb_n))
			return (false);
		(*i)++;
	}
	if (!rgb_n_are_correct(rgb_n, line, i, rgb))
		return (NULL);
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
