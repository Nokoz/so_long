/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:24:56 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/08 15:41:26 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_init_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->map.x = (int)ft_strlen(game->map.map[0]) - 1;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.x * W, game->map.y * H,
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

void	ft_test_img(t_game *g)
{
	int i = 0;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_up.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_right.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_down.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_left.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->collectible.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit.ptr, i++ * W, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit_open.ptr, i++ * W, 0);
}
