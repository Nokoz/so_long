/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 16:57:05 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

	//ft_printf("ici\n");
int	main(int ac, char **av)
{
	t_game	*game;

	ft_valid_arg(ac, av);
	game = malloc(sizeof(t_game));
	ft_parse_map(av[1], game);
	ft_init_win(game);
	ft_init_var(game);
	ft_load_image(game);
	ft_display_map(game);
	//ft_check_map
	//ft_game
	mlx_hook(game->win_ptr, 17, 0, ft_exit, game);
	mlx_loop(game->mlx_ptr);
	ft_free_full(game);
	return (0);
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
