/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:43:06 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 17:19:08 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define H 100
# define W 100

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_RIFGT	124
# define KEY_DOWN 	125
# define KEY_LEFT	123
# define KEY_ESC	53

#include "../libft_2.0/libft.h"
#include <mlx.h>

typedef struct s_sprite
{
	void	*ptr;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef	struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	player_up;
	t_sprite	player_right;
	t_sprite	player_down;
	t_sprite	player_left;
	t_sprite	floor;
	t_sprite	wall;
	t_sprite	collectible;
	t_sprite	exit;
	t_sprite	exit_open;
	int			*x;
	int			direction;
	int			to_loot;
	t_map	 	map;
}				t_game;

void		ft_parse_map(char *file, t_game *game);
char		*ft_append(char **s1, const char *s2);
void		ft_free_full(t_game *game);
void		ft_free_map(t_game *game);
void		ft_valid_map(t_game *game, char *map);
void		ft_error_print(t_game *g, char *str, char *map);
void		ft_init_win(t_game *game);
void		ft_load_image(t_game *game);
t_sprite	ft_sprite(t_game *game, char *path);
int			ft_exit(t_game* g);
void		ft_display_map(t_game *g);
void		ft_valid_arg(int ac, char **av);
void		ft_show_player(t_game *g, int i, int j);
void		ft_init_var(t_game *g);
void		ft_show_exit(t_game *g, int i, int j);
int			ft_count_collectible(t_game* g);
#endif
