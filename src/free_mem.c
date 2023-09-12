/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:55:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/12 14:38:40 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_print(t_game *g, char *str, char *map)
{
	ft_printf("%s\n", str);
	ft_free_map(g);
	free(g);
	free(map);
	exit(2);
}

void	ft_free_full(t_game *game)
{
	ft_free_map(game);
	ft_destroy_img(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

int	ft_exit(t_game *g)
{
	ft_free_full(g);
	exit(2);
	return (0);
}

void	ft_destroy_img(t_game *g)
{
	mlx_destroy_image(g->mlx_ptr, g->player_up.ptr);
	mlx_destroy_image(g->mlx_ptr, g->player_right.ptr);
	mlx_destroy_image(g->mlx_ptr, g->player_down.ptr);
	mlx_destroy_image(g->mlx_ptr, g->player_left.ptr);
	mlx_destroy_image(g->mlx_ptr, g->floor.ptr);
	mlx_destroy_image(g->mlx_ptr, g->wall.ptr);
	mlx_destroy_image(g->mlx_ptr, g->collectible.ptr);
	mlx_destroy_image(g->mlx_ptr, g->exit.ptr);
	mlx_destroy_image(g->mlx_ptr, g->exit_open.ptr);
}
