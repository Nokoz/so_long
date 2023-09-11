/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:24:56 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 14:52:23 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_var(t_game *g)
{
	g->direction = 2;
	g->to_loot = ft_count_collectible(g);
	ft_printf("to_loot = %d\n", g->to_loot);
}

int	ft_count_collectible(t_game* g)
{
	
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (i < g->map.y)
	{
		j = 0;
		while (j <= g->map.x)
		{
			if (g->map.map[i][j] == 'C')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

void	ft_init_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->map.x = (int)ft_strlen(game->map.map[0]);
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
