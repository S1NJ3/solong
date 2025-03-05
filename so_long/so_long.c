/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:03:39 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/05 18:18:43 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bibi/so_long.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	t_game *game;

	game = malloc(sizeof(t_game)); // Allouez de la mémoire pour gamey
    gameinit(game);
    if (ac != 2)
    {
        write(1,"Erreur: nombre d'arguments invalide.\n", 38);
        freeallgame(game);
        return (0);
    }
	if	(validname(av[1]) == 0)
		write(1, "Le nom du fichier est invalide.\n", 32);
	else
		game->map->map = fdtotab(game->map->map, av[1]);
	if (!allchecks(game))
	{
		write(1, "la map est invalide\n", 20);
		return(0);
	}
	if (!validpath(game))
		write(1, "La map n'a pas de chemin valide.\n", 33);
	else
		write(1, "tout est bon\n", 13);
	mlx_init(game->minilib);
	mlx_key_hook(game->minilib->win, key_hook, game);
	mlx_loop(game->minilib->mlx);
	return (0);
}

	
	