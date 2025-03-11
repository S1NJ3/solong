/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawed <jawed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:38 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/06 17:46:40 by jawed            ###   ########.fr       */
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
	t_map	*map;
	t_char	*checks;
	t_player	*player;

	map = malloc(sizeof(t_map));
	checks = malloc(sizeof(t_char));
	player = malloc(sizeof(t_player));
	if (map == NULL || checks == NULL)
	{
		printf("Erreur: allocation de mémoire échouée caca pipi.\n");
		exit(0);
	}
	game->map = map;
	game->checks = checks;
	game->player = player;
	init_map(game->map);
	init_checks(game->checks);
}
