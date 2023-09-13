/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/13 12:27:40 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_show_exit(t_game *g, int i, int j)
{
	if (g->to_loot == 0)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->exit_open.ptr, j * W, i * H);
	else
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->exit.ptr, j * W, i * H);
}

void	ft_show_player(t_game *g, int i, int j)
{
	if (g->direction == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->player_up.ptr, j * W, i * H);
	if (g->direction == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->player_right.ptr, j * W, i * H);
	if (g->direction == 3)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->player_down.ptr, j * W, i * H);
	if (g->direction == 4)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->player_left.ptr, j * W, i * H);
	g->player_x = j;
	g->player_y = i;
	ft_printf("Moves = %d\n", g->moves);
}

void	ft_display_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map.y)
	{
		j = -1;
		while (j++ <= g->map.x)
		{
			if (g->map.map[i][j] == '1')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
					g->wall.ptr, j * W, i * H);
			else if (g->map.map[i][j] == '0')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
					g->floor.ptr, j * W, i * H);
			else if (g->map.map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
					g->collectible.ptr, j * W, i * H);
			else if (g->map.map[i][j] == 'P')
				ft_show_player(g, i, j);
			else if (g->map.map[i][j] == 'E')
				ft_show_exit(g, i, j);
		}
		i++;
	}
}
