/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:58 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/12 17:44:03 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_handle_key(int key, t_game *g)
{
	if (key == KEY_ESC)
		ft_exit(g);
	if (key == KEY_W || key == KEY_UP)
		ft_move_player(g, 1);
	if (key == KEY_D || key == KEY_RIGHT)
		ft_move_player(g, 2);
	if (key == KEY_S || key == KEY_DOWN)
		ft_move_player(g, 3);
	if (key == KEY_A || key == KEY_LEFT)
		ft_move_player(g, 4);
	return (0);
}

void	ft_move_player(t_game *g, int dir)
{
	g->direction = dir;
	if (dir == 1)
	{
		g->map.map[g->player_y][g->player_x] = '0';
		g->map.map[g->player_y - 1][g->player_x] = 'P';
	}
	if (dir == 2)
	{
		g->map.map[g->player_y][g->player_x] = '0';
		g->map.map[g->player_y][g->player_x + 1] = 'P';
	}
	if (dir == 3)
	{
		g->map.map[g->player_y][g->player_x] = '0';
		g->map.map[g->player_y + 1][g->player_x] = 'P';
	}
	if (dir == 4)
	{
		g->map.map[g->player_y][g->player_x] = '0';
		g->map.map[g->player_y][g->player_x - 1] = 'P';
	}
	ft_display_map(g);
}
