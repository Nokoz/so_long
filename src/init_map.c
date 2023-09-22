/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:21:53 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/22 11:27:23 by gvardaki         ###   ########.fr       */
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
	game->map.x = (int)ft_strlen(game->map.map[0]);
	ft_valid_map(game, temp_map);
	free(temp_map);
}

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
	ft_check_map(g, map);
}

void	ft_check_map(t_game *g, char *map)
{
	int	i;

	i = 0;
	while (i < g->map.x - 1)
	{
		if (g->map.map[0][i] != '1' || g->map.map[g->map.y - 1][i] != '1')
			ft_error_print(g, "Map must by surronded by walls", map);
		i++;
	}
	i = 0;
	while (i < g->map.y - 1)
	{
		if (g->map.map[i][0] != '1' || g->map.map[i][g->map.x - 1] != '1')
			ft_error_print(g, "Map must by surronded by walls", map);
		i++;
	}
	if (ft_count_obj(g, 'P') != 1)
		ft_error_print(g, "Only one player(P) allowed", map);
	if (ft_count_obj(g, 'E') != 1)
		ft_error_print(g, "Only one exit(E) allowed", map);
}

void	ft_check_path(t_game *g)
{
	char	**map;

	map = ft_dup_map(g);
	if (!ft_find_path(g->to_loot, g->player_x, g->player_y, map))
	{
		ft_free_map(map);
		ft_error_print(g, "Map is impossible to win", NULL);
	}
	ft_free_map(map);
}

bool	ft_find_path(int to_loot, int x, int y, char **map)
{
	static int	coins = 0;
	static bool	exit = false;

	if (map[y][x] == '1')
		return (false);
	else if (map[y][x] == 'C')
		coins += 1;
	else if (map[y][x] == 'E')
		exit = true;
	map[y][x] = '1';
	ft_find_path(to_loot, x + 1, y, map);
	ft_find_path(to_loot, x - 1, y, map);
	ft_find_path(to_loot, x, y + 1, map);
	ft_find_path(to_loot, x, y - 1, map);
	return (coins == to_loot && exit);
}
