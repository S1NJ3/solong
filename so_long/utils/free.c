/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:12:24 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 17:33:07 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

void	freemap(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map->map[i])
		{
			free(game->map->map[i]);
			i++;
		}
		free(game->map->map);
		game->map->map = NULL;
		game->map->xspawn = 0;
		game->map->yspawn = 0;
		game->map->x = 0;
		game->map->y = 0;
	}
}

void	freeclonemap(t_game *game)
{
	int	i;

	if (game->map && game->map->clonemap)
	{
		i = 0;
		while (game->map->clonemap[i])
		{
			free(game->map->clonemap[i]);
			i++;
		}
		free(game->map->clonemap);
		game->map->clonemap = NULL;
	}
}

void	freeminilib(t_game *game)
{
	if (game->minilib)
	{
		destroyimg(game->minilib);
		mlx_destroy_window(game->minilib->mlx, game->minilib->win);
		mlx_destroy_display(game->minilib->mlx);
		mlx_loop_end(game->minilib->mlx);
	}
}

void	freechecks(t_game *game)
{
	game->checks->carapos = 0;
	game->checks->kolektibl = 0;
	game->checks->exitexist = 0;
	game->checks->wallstatus = 0;
	game->checks->koclone = 0;
	game->checks->exitclone = 0;
	game->checks->exx = 0;
	game->checks->exy = 0;
	game->checks->mapwidth = 0;
	game->checks->mapheight = 0;
	free (game->checks);
}

void	freeallgame(t_game *game)
{
	if (game->checks)
		freechecks(game);
	game->checks = NULL;
	if (game->player)
		free(game->player);
	game->player = NULL;
	if (game->minilib->unfree == 1)
		freeminilib(game);
	free(game->minilib->mlx);
	free(game->minilib);
	freemap(game);
	freeclonemap(game);
	free(game->map);
	game->map = NULL;
	free(game);
	game = NULL;
}
