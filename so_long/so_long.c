/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:03:39 by jrighi            #+#    #+#             */
/*   Updated: 2025/02/14 19:05:41 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bibi/so_long.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	t_game *game;

	game = malloc(sizeof(t_game)); // Allouez de la mémoire pour gamey
	
    if (game == NULL)
    {
        printf("Erreur: allocation de mémoire échouée.\n");
        return (0);
    }

    gameinit(game);
    if (ac != 2)
    {
        printf("Erreur: nombre d'arguments invalide.\n");
        free(game); // Libérez la mémoire allouée pour game
        return (0);
    }
	if (ac != 2)
	{
		printf("Erreur: nombre d'arguments invalide.\n");
		return (0);
	}
	game->map.map = fdtotab(game->map.map, av[1]);
	int i = 0;
	while (i != 4)
	{
		printf("%s\n", game->map.map[i]);
		i++;
	}
	if (game->map.map == NULL)
	{
		printf("Erreur lors de la lecture de la map.\n");
		return (0);
	}
	if (validpath(game))
		printf("La map est a un chemin valide.\n");
	else
		printf("La map n'a pas de chemin valide.\n");
	return (0);
}

	
	