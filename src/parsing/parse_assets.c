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

// void	handle_nl_start(int fd, t_map *map_data, char *file_content, char *line)
// {
// 	ft_printf("Error: map cannot have an empty newline!\n");
// 	free(map_data);
// 	free(file_content);
// 	free(line);
// 	close(fd);
// 	exit(1);
// }

// void	no_content(int fd, t_map *map_data, char *file_content)
// {
// 	ft_printf("Error: file is empty!\n");
// 	free(map_data);
// 	free(file_content);
// 	close(fd);
// 	exit(1);
// }

// static char	*parse_map(int fd, t_map *map_data, char *file_content, char *line)
// {
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	while (line != NULL)
// 	{
// 		if (line[0] == '\n')
// 			handle_nl_start(fd, map_data, file_content, line);
// 		if (file_content == NULL)
// 			file_content = ft_strdup(line);
// 		else
// 		{
// 			temp = ft_strjoin(file_content, line);
// 			free(file_content);
// 			file_content = temp;
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	if (!file_content)
// 		no_content(fd, map_data, file_content);
// 	return (file_content);
// }

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
	(void)game;


	fd = open(file, O_RDONLY);
	if (!has_file_extension(file, ".cub") || fd < 0) 
	{
		ft_printf("Error: file does not exist or has wrong extension format\n");
		close(fd);
        return (NULL);
	}	
	if(!collect_map(fd, &game->data->map_data))
	{	
		close(fd);
		return (false);
	}
	close(fd);
	print_map(game->data->map_data);
	return (true);
}	


bool	parse_assets(char	*file_name, t_game *game) // error handling if we have more 
{
    (void)game;
    if(!check_map(file_name, game))
        return (false);
    
    
    // if !check_map return false	
    /*Fullfill structure with textures and info*/
    return (true);
}	

