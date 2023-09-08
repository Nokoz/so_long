/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:21:53 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/08 11:55:39 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_parse_map(char *file, t_game *game)
{
	int		fd;
	char	*temp_map;
	char	*line;

	temp_map = ft_strdup("");
	fd = open(file, O_RDONLY);
	game->map.y = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		temp_map = ft_append(&temp_map, line);
		free(line);
		game->map.y++;
	}
	close(fd);
	game->map.map = ft_split(temp_map, '\n');
	if (ft_valid_map(temp_map))
		exit(1);
	free(temp_map);
}

//make void and imp fct error
int	ft_valid_map(char *map)
{
	int  i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_printf("Map start with an empty line\n");
		return (1);
	}
	else if (map[ft_strlen(map) - 2] == '\n')
	{
		free(map);
		ft_printf("Empty line at end of the map\n");
		return (1);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_printf("Empty line in the middle of the map\n");
			return (1);
		}
		i++;
	}
	return (0);
}
