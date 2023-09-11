/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:55:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 17:22:04 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_print(t_game *g, char *str, char *map)
{
	ft_printf("%s\n", str);
	free(map);
	ft_exit(g);
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
	while (i <= game->map.y)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

int	ft_exit(t_game *g)
{
	ft_free_full(g);
	exit(2);
	return (0);
}
