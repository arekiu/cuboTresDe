/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:43:41 by jslusark          #+#    #+#             */
/*   Updated: 2025/03/28 13:50:57 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	has_file_extension(char *file, char *extension)
{
	int	file_len;
	int	ext_len;

	if (!file || !extension) //!extension makes no sense as it will never be null as passed as param
		return (false);
	file_len = ft_strlen(file) - 1;
	ext_len = ft_strlen(extension) - 1;
	if (ext_len > file_len)
	return (false);
	while (ext_len >= 0)
	{
		if (file[file_len] != extension[ext_len])
		return (0);
		file_len--;
		ext_len--;
	}
	while(file_len >= 0) // added this as a warmup and handle filenames like map.ber.cub
	{
		if (file[file_len] == '/') // if we passed the path to file, the check ends here
			break;
		if (file[file_len] == '.')
			return (false);
		file_len--;
	}
	return (true);
}

bool	check_map(char *file, t_game *game) // returns null if fails
{
	int		fd;
	(void) game;


	fd = open(file, O_RDONLY);
	if (!has_file_extension(file, ".cub") || fd < 0)
	{
		ft_printf("Error: file does not exist or has wrong extension format\n");
		close(fd);
        return (NULL);
	}
	if(!collect_map(fd, &game->data->map, game))
	{
		close(fd);
		return (false);
	}
	close(fd);
	print_map(game->data);
	// exit(0); // removing this after testing
	return (true);
}


bool	parse_assets(char	*file_name, t_game *game) // error handling if we have more
{
    (void)game;
    if(!check_map(file_name, game))
        return (false);
	// parse_map(game->data->map, game); -- parse items in the map array
	// parse textures -- parse textures if they can be found and valid
    return (true);
}

