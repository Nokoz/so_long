/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 13:50:02 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_show_exit(t_game *g, int i, int j)
{
	if (g->to_loot == 0)	
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit_open.ptr, j * W, i * H);
	else
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit.ptr, j * W, i * H);
}

void	ft_show_player(t_game *g, int i, int j)
{
	if (g->direction == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_up.ptr, j * W, i * H);
	if (g->direction == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_right.ptr, j * W, i * H);
	if (g->direction == 3)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_down.ptr, j * W, i * H);
	if (g->direction == 4)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player_left.ptr, j * W, i * H);
}
