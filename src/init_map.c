/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:21:53 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 17:21:17 by gvardaki         ###   ########.fr       */
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp_map = ft_append(&temp_map, line);
		free(line);
		game->map.y++;
	}
	close(fd);
	game->map.map = ft_split(temp_map, '\n');
	ft_valid_map(game, temp_map);
	free(temp_map);
}

//make void and imp fct error
void	ft_valid_map(t_game *g, char *map)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
		ft_error_print(g, "Map start with an empty line", map);
	else if (map[ft_strlen(map) - 2] == '\n')
		ft_error_print(g, "Empty line at end of the map", map);
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			ft_error_print(g, "Empty line in the middle of the map", map);
		i++;
	}
}
