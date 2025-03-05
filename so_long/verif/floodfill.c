/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:35:32 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/04 20:40:14 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int flooderrorchek(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->checks->mapwidth
        || y >= game->checks->mapheight
        || y >= slong_strlen(game->map->clonemap[0]))
        return (0);
    return (1);
}

void floodcount(t_game *game, int x, int y)
{
    if (game->map->clonemap[y][x] == 'C')
    {
        game->checks->koclone--;
    }
    else if (game->map->clonemap[y][x] == 'E')
    {
        game->checks->exitclone--;
    }
}

int flood_fill(t_game *game, int x, int y)
{
    static int i = 0;
    static int j = 0;

    if (!flooderrorchek(game, x, y))
        return(0);
    if (game->map->clonemap[y][x] == '1')
        return(0);
    if (game->map->clonemap[y][x] == 'C')
        i++;
    if (game->map->clonemap[y][x] == 'E')
        j++;
    game->map->clonemap[y][x] = '1';
    if (j == 1)
        game->map->clonemap[game->checks->exy][game->checks->exx] = '0';
    if (flood_fill(game, x - 1, y))
    return (1);
    if (flood_fill(game, x + 1, y))
    return (1);
    if (flood_fill(game, x, y - 1))
        return (1);    
    if (flood_fill(game, x, y + 1))
        return (1);
    if (game->checks->kolektibl == i && game->checks->exitexist == j)
        return (1);
    return (0);
}


int	validpath(t_game *game)
{
	game->map->clonemap = mapcopy(game->map->map);
	if (game->map->clonemap == NULL)
		return (0);
	if (flood_fill(game, game->map->xspawn, game->map->yspawn))
    {
        free(game->map->clonemap);
        return (1);
    }
    free(game->map->clonemap);
	return (0);
}

/*int	main(void)
{
    // Exemple de tableau de carte (map) pour tester
    char *map[] = {
        "111111",
        "1C00P1",
        "101001",
        "1C1E01",
        "111111",
        NULL
    };

    // Initialisation de la structure t_game
    t_game game;
    game.checks.kolektibl = 2; // Nombre de collectibles
    game.checks.koclone = 2; // Nombre de collectibles pour floodfill
    game.checks.exitexist = 1;
    game.checks.exitclone = 1; // Nombre d'exits pour floodfill
    game.checks.wallstatus = 1;
    game.checks.carapos = 1;
    game.map.map = map;
    game.map.xspawn = 4; // Position de départ (x)
    game.map.yspawn = 1; // Position de départ (y)

    // Appel de la fonction validpath
    int result = validpath(&game);

    // Affichage du résultat
    if (result)
        printf("Un chemin valide existe dans la carte.\n");
    else
        printf("Aucun chemin valide n'existe dans la carte.\n");

    return 0;
}*/
