/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:20:14 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/22 11:28:11 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_append(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	ft_flag_exit(t_game *g)
{
	if (g->flag == 1)
		g->map.map[g->player_y][g->player_x] = 'E';
	--g->flag;
}

char	**ft_dup_map(t_game *g)
{
	int		i;
	char	**dup;

	dup = ft_calloc(g->map.y + 1, sizeof (char *));
	if (!dup)
		ft_error_print(g, "Malloc error", NULL);
	i = 0;
	while (i < g->map.y)
	{
		dup[i] = ft_strdup(g->map.map[i]);
		if (!dup[i])
		{
			ft_free_map(dup);
			ft_error_print(g, "Malloc error", NULL);
		}
		i++;
	}
	return (dup);
}

void	ft_set_start_position(t_game *g)
{
	int	x;
	int	y;

	y = 1;
	while (g->map.map[y])
	{
		x = 1;
		while (g->map.map[y][x])
		{
			if (g->map.map[y][x] == 'P')
			{
				g->player_y = y;
				g->player_x = x;
			}
			++x;
		}
		++y;
	}
}
