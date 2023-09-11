/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:22:20 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/11 12:22:48 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_valid_arg(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_printf("Wrong number of agruments, only one map allowed\n");
		exit(1);
	}
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
	{
		ft_printf("Map must be a .ber file\n");
		exit(1);
	}
}
