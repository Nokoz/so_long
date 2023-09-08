/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/08 15:41:42 by gvardaki         ###   ########.fr       */
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
	ft_load_image(game);
	//ft_test_img(game);
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
	while (i < g->map.x)
	{
		j = 0;
		while (j < g->map.y)
		{
			if (g->map.map[i][j] == '1')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall.ptr, j * W, i * H);
			j++;
		}
		i++;
	ft_printf("ici\n");
	}
}
