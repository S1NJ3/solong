/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:35:32 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/12 12:32:46 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	flooderrorchek(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->checks->mapwidth
		|| y >= game->checks->mapheight
		|| y >= slong_strlen(game->map->clonemap[0]))
		return (0);
	return (1);
}

void	floodcount(t_game *game, int x, int y)
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

int	flood_fill(t_game *game, int x, int y)
{
	static int	i = 0;
	static int	j = 0;

	if (!flooderrorchek(game, x, y))
		return (0);
	if (game->map->clonemap[y][x] == '1')
		return (0);
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
		return (errormsg("Error: allocation de mémoire échouée.\n"));
	if (flood_fill(game, game->map->xspawn, game->map->yspawn))
		return (1);
	return (errormsg("Error: chemin invalide.\n"));
}
