/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:38 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/12 12:14:00 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->clonemap = NULL;
	map->xspawn = 0;
	map->yspawn = 0;
	map->x = 0;
	map->y = 0;
}

void	init_checks(t_char *checks)
{
	checks->carapos = 0;
	checks->kolektibl = 0;
	checks->exitexist = 0;
	checks->wallstatus = 0;
	checks->koclone = 0;
	checks->exitclone = 0;
}

void	gameinit(t_game *game)
{
	t_map		*map;
	t_char		*checks;
	t_player	*player;
	t_minilib	*minilib;

	map = malloc(sizeof(t_map));
	checks = malloc(sizeof(t_char));
	player = malloc(sizeof(t_player));
	minilib = malloc(sizeof(t_minilib));
	if (map == NULL || checks == NULL || player == NULL)
	{
		printf("Erreur: allocation de mémoire échouée caca pipi.\n");
		exit(0);
	}
	game->map = map;
	game->checks = checks;
	game->player = player;
	game->minilib = minilib;
	init_map(game->map);
	init_checks(game->checks);
	player->x = 0;
	player->y = 0;
}
