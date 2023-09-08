/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/08 11:02:36 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char** av)
{
	t_game *game;
	(void)ac;

	game = malloc(sizeof(t_game));
	ft_parse_map(av[1], game);
	ft_init_win(game);
	//ft_load_image(game);
	//ft_check_map
	//ft_game
	mlx_loop(game->mlx_ptr);
	ft_free_full(game);
	return (0);
}

void	ft_free_full(t_game *game)
{
	ft_free_map(game);
	free(game);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void ft_init_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->map_x = ft_strlen(game->map[0]);
	ft_printf("ici\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_x * W, game->map_y * H,
			"so_long");
}

void	ft_load_image(t_game *game)
{
	game->player_left = ft_sprite(game, "img/blue_left.xpm");
	game->player_right = ft_sprite(game, "img/blue_right.xpm");
	game->player_down = ft_sprite(game, "img/blue_down.xpm");
	game->player_up = ft_sprite(game, "img/blue_up.xpm");
	game->floor = ft_sprite(game, "img/white.xpm");
	game->wall = ft_sprite(game, "img/grey.xpm");
	game->collectible = ft_sprite(game, "img/yellow.xpm");
	game->exit = ft_sprite(game, "img/red.xpm");
	game->exit_open = ft_sprite(game, "img/green.xpm");
}

t_sprite	ft_sprite(t_game *game, char *path)
{
	t_sprite	sprite;

	sprite.ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &sprite.x, &sprite.y);
	return (sprite);
}
