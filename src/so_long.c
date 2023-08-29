/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:06:55 by gvardaki          #+#    #+#             */
/*   Updated: 2023/08/29 15:03:17 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char** av)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	ft_parse_map(av[1], game);
	ft_printf("ici\n");
	//ft_check_map
	//ft_init_win
	//ft_game
	int i = 0;
	while (i <= game->map_y)
	{
		ft_printf("%s\n", game->map[i]);
		i++;	
	}
	return (0);
}

void	ft_parse_map(char *file, t_game *game)
{
	int	fd;
	int i;
	char **ret;

	fd = open(file, O_RDONLY);
	i = 0;
	while(1)
	{
		ret[i] = get_next_line(fd);
		ft_printf("%s", ret[i]);
		if (ret[i] == NULL)
			break;
		i++;
	}
	game->map = malloc(sizeof(char *) * 4);
	game->map[0] = ft_strdup(ret[0]);
	close(fd);
	game->map_y = i;
	ft_printf("la\n");
}
