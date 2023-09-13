/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:58 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/13 12:27:43 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_handle_key(int key, t_game *g)
{
	if (key == KEY_ESC)
		ft_exit(g);
	if (key == KEY_W || key == KEY_UP)
	{
		if (ft_valid_move(g, 1))
			ft_move_player(g, 1);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		if (ft_valid_move(g, 2))
			ft_move_player(g, 2);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		if (ft_valid_move(g, 3))
			ft_move_player(g, 3);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		if (ft_valid_move(g, 4))
			ft_move_player(g, 4);
	}
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
	g->moves++;
	ft_display_map(g);
}

int	ft_valid_move(t_game *g, int dir)
{
	if (dir == 1)
	{
		if (ft_move_to_object(g, g->player_y - 1, g->player_x))
			return (0);
	}
	if (dir == 2)
	{
		if (ft_move_to_object(g, g->player_y, g->player_x + 1))
			return (0);
	}
	if (dir == 3)
	{
		if (ft_move_to_object(g, g->player_y + 1, g->player_x))
			return (0);
	}
	if (dir == 4)
	{
		if (ft_move_to_object(g, g->player_y, g->player_x - 1))
			return (0);
	}
	return (1);
}

int	ft_move_to_object(t_game *g, int y, int x)
{
	if (g->map.map[y][x] == '1')
		return (1);
	else if (g->map.map[y][x] == 'C')
	{
		g->to_loot--;
		return (0);
	}
	else if (g->map.map[y][x] == 'E' && g->to_loot != 0)
		return (1);
	else if (g->map.map[y][x] == 'E' && g->to_loot == 0)
	{
		ft_printf("GG\n");
		return (0);
	}
	return (0);
}
