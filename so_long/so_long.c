/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:03:39 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 18:10:26 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bibi/so_long.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		if (validname(av[1]) == 1)
		{
			game = malloc(sizeof(t_game));
			gameinit(game);
			game->map->map = fdtotab(game->map->map, av[1]);
			if (allchecks(game))
			{
				mlxinit(game->minilib, game);
				mlx_key_hook(game->minilib->win, key_hook, game);
				mlx_hook(game->minilib->win, 17, 1L << 0, mlxdestroyall, game);
				mlx_loop(game->minilib->mlx);
				brexit(game);
			}
		}
	}
	else
	{
		write (1, "Error: nombre d'arguments invalide.\n", 37);
		return (0);
	}
	return (0);
}
