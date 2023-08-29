/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:43:06 by gvardaki          #+#    #+#             */
/*   Updated: 2023/08/29 12:24:04 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define H 100
# define W 100

#include "../libft_2.0/libft.h"

typedef struct s_player
{
	void	*ptr;
	char	dir;
	int		x;
	int		y;
}				t_player;

typedef	struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_player*player;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*exit_open;
	int		*x;
	char 	**map;
	int		map_x;
	int		map_y;
}				t_game;

void	ft_parse_map(char *file, t_game *game);
#endif
