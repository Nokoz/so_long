/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/13 12:44:50 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	mlx_key_hook(game->win_ptr, ft_handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, ft_exit, game);
	mlx_loop(game->mlx_ptr);
	ft_exit(game);
	return (0);
}
