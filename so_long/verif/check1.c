/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:29:47 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 18:07:21 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	kolektichek(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->map[i] != NULL)
	{
		j = 0;
		while (game->map->map[i][j] != '\0')
		{
			if (game->map->map[i][j] == 'C')
				game->checks->kolektibl++;
			j++;
		}
		i++;
	}
	if (game->checks->kolektibl < 1)
		return (errormsg("Error: pas de collectibles.\n"));
	else if (game->checks->kolektibl >= 1)
	{
		game->checks->koclone = game->checks->kolektibl;
		return (game->checks->kolektibl);
	}
	return (0);
}

int	spawnchek(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->map[i] != NULL)
	{
		j = 0;
		while (game->map->map[i][j] != '\0')
		{
			if (game->map->map[i][j] == 'P')
			{
				game->checks->carapos++;
				coordassign(game, i, j);
			}
			j++;
		}
		i++;
	}
	if (game->checks->carapos != 1)
		return (errormsg("Error: nombre de spawn invalide.\n"));
	else if (game->checks->carapos == 1)
		return (1);
	return (0);
}

int	exichek(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->map[i] != NULL)
	{
		j = 0;
		while (game->map->map[i][j] != '\0')
		{
			if (game->map->map[i][j] == 'E')
			{
				game->checks->exitexist++;
				game->checks->exx = j;
				game->checks->exy = i;
			}
			j++;
		}
		i++;
	}
	game->checks->exitclone = game->checks->exitexist;
	if (game->checks->exitexist == 1)
		return (1);
	return (errormsg("Error: nombre de sortie invalide.\n"));
}

int	wallchek(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	game->checks->wallstatus = 0;
	printf("k = %d\n", k);
	while (game->map->map[i][j] != '\0')
		j++;
	if (linewallchek(0, game->map->map) == 0)
		return (errormsg("Error: murs invalides.\n"));
	i++;
	while (i < k - 1)
	{
		if (game->map->map[i][0] != '1' || game->map->map[i][j - 2] != '1')
			return (errormsg("Error: murs invalides.\n"));
		i++;
	}
	if (linewallchek(i, game->map->map) == 0)
		return (errormsg("Error: murs invalides.\n"));
	game->checks->wallstatus = 1;
	return (1);
}

int	allchecks(t_game *game)
{
	if (validrectangle(game->map->map, game)
		&& kolektichek(game) && exichek(game)
		&& wallchek(game) && spawnchek(game)
		&& validpath(game))
	{
		return (1);
	}
	else
		brexit(game);
	return (0);
}
