/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:04:19 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/20 15:02:44 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	has_file_extension(char *file, char *extension)
{
	int	file_len;
	int	ext_len;

	//!extension makes no sense as it will never be null as passed as param
	if (!file || !extension)
		return (false);
	file_len = ft_strlen(file) - 1;
	ext_len = ft_strlen(extension) - 1;
	if (ext_len > file_len)
		return (false);
	while (ext_len >= 0)
	{
		if (file[file_len] != extension[ext_len])
			return (false);
		file_len--;
		ext_len--;
	}
	// added this as a warmup and handle filenames like map.ber.cub
	while (file_len >= 0)
	{
		// if we passed the path to file, the check ends here
		if (file[file_len] == '/')
			break ;
		if (file[file_len] == '.')
			return (false);
		file_len--;
	}
	return (true);
}

// add also open close file checks