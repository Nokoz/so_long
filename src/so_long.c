/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/08 15:11:38 by gvardaki         ###   ########.fr       */
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
	ft_test_img(game);
	//ft_check_map
	//ft_game
	mlx_hook(game->win_ptr, 17, 0, ft_exit, game);
	mlx_loop(game->mlx_ptr);
	ft_free_full(game);
	return (0);
}
