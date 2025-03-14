/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:35:16 by jawed             #+#    #+#             */
/*   Updated: 2025/03/14 17:15:39 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	upmouvement(t_game *game)
{
	if (game->map->map[game->player->y - 1][game->player->x] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return (0);
	}
	if (game->map->map[game->player->y - 1][game->player->x] == 'E')
	{
		if (game->checks->kolektibl == 0)
			brexit (game);
		else if (game->checks->kolektibl > 0)
		{
			spky(game, -1);
			return  (0);
		}
	}
	if (game->map->map[game->player->y - 1][game->player->x] == 'C')
		game->checks->kolektibl--;
	if (game->map->map[game->player->y][game->player->x] == 'T')
		return (spky2(game, -1));
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->y--;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
	display_move(game);
	return (0);
}

int	downmouvement(t_game *game)
{
	if (game->map->map[game->player->y + 1][game->player->x] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return (0);
	}
	if (game->map->map[game->player->y + 1][game->player->x] == 'E')
	{
		if (game->checks->kolektibl == 0)
			brexit (game);
		else if (game->checks->kolektibl > 0)
		{
			spky(game, 1);
			return (0);
		}
	}
	if (game->map->map[game->player->y + 1][game->player->x] == 'C')
		game->checks->kolektibl--;
	if (game->map->map[game->player->y][game->player->x] == 'T')
		return (spky2(game, 1));
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->y++;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
	display_move(game);
	return (0);
}

int	leftmouvement(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x - 1] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return (0);
	}
	if (game->map->map[game->player->y][game->player->x - 1] == 'E')
	{
		if (game->checks->kolektibl == 0)
			brexit (game);
		else if (game->checks->kolektibl > 0)
		{
			spkx(game, -1);
			return (0);
		}
	}
	if (game->map->map[game->player->y][game->player->x - 1] == 'C')
		game->checks->kolektibl--;
	if (game->map->map[game->player->y][game->player->x] == 'T')
		return (spkx2(game, -1));
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->x--;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
	display_move(game);
	return (0);
}

int	rightmouvement(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x + 1] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return (0);
	}
	if (game->map->map[game->player->y][game->player->x + 1] == 'E')
	{
		if (game->checks->kolektibl == 0)
			brexit (game);
		else if (game->checks->kolektibl > 0)
		{
			spkx(game, 1);
			return (0);
		}
	}
	if (game->map->map[game->player->y][game->player->x + 1] == 'C')
		game->checks->kolektibl--;
	if (game->map->map[game->player->y][game->player->x] == 'T')
		return (spkx2(game, 1));
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->x++;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
	display_move(game);
	return (0);
}
