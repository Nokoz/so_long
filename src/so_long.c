/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/06 13:26:36 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char** av)
{
	t_game *game;
	int i;
	(void)ac;

	game = malloc(sizeof(t_game));
	ft_parse_map(av[1], game);
	//ft_check_map
	//ft_init_win
	//ft_game
	i = 0;
//	ft_printf("%d\n", game->map_y);
	while (i < game->map_y)
	{
		ft_printf("%s\n", game->map[i]);
		i++;	
	}
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
		ft_printf("i = %d\n", i);
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
