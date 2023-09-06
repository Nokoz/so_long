/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/06 15:48:04 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char** av)
{
	t_game *game;
	(void)ac;

	game = malloc(sizeof(t_game));
	ft_parse_map(av[1], game);
	ft_init_mlx(game);
//	ft_load_image(game);
	//ft_check_map
	//ft_init_win
	//ft_game
	ft_free_full(game);
	return (0);
}

void	ft_free_full(t_game *game)
{
	ft_free_map(game);
	free(game);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
}

void	ft_load_image(t_game *game)
{
	(void)game;	
}
