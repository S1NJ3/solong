/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:12:24 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/12 12:35:24 by jrighi           ###   ########.fr       */
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
	}
}

void	freeclonemap(t_game *game)
{
	int	i;

	if (game->map)
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
		free(game->minilib->mlx);
		free(game->minilib);
		game->minilib->mlx = NULL;
		game->minilib->win = NULL;
		game->minilib->tile = NULL;
		game->minilib->fish1 = NULL;
		game->minilib->fish2 = NULL;
		game->minilib->kolek = NULL;
		game->minilib->exit = NULL;
		game->minilib->unfree = 0;
		game->minilib = NULL;
	}
}

void	freeallgame(t_game *game)
{
	if (game->checks)
		free(game->checks);
	game->checks = NULL;
	if (game->player)
		free(game->player);
	game->player = NULL;
	if (game->minilib->unfree == 1)
		freeminilib(game);
	freemap(game);
	freeclonemap(game);
	free(game->map);
	game->map = NULL;
	free(game);
	game = NULL;
}

void	brexit(t_game *game)
{
	freeallgame(game);
	exit (0);
}
