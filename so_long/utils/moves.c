/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:35:16 by jawed             #+#    #+#             */
/*   Updated: 2025/03/12 12:34:41 by jrighi           ###   ########.fr       */
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

void	upmouvement(t_game *game)
{
	if (game->map->map[game->player->y - 1][game->player->x] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return ;
	}
	if (game->map->map[game->player->y - 1][game->player->x] == 'E')
	{
		if (game->checks->kolektibl == 0)
			exit (0);
		else if (game->checks->kolektibl > 0)
		{
			ft_putstr("Il te reste des collectibles à ramasser\n");
			return ;
		}
	}
	if (game->map->map[game->player->y - 1][game->player->x] == 'C')
		game->checks->kolektibl--;
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->y--;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
}

void	downmouvement(t_game *game)
{
	if (game->map->map[game->player->y + 1][game->player->x] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return ;
	}
	if (game->map->map[game->player->y + 1][game->player->x] == 'E')
	{
		if (game->checks->kolektibl == 0)
			exit (0);
		else if (game->checks->kolektibl > 0)
		{
			ft_putstr("Il te reste des collectibles à ramasser\n");
			return ;
		}
	}
	if (game->map->map[game->player->y + 1][game->player->x] == 'C')
		game->checks->kolektibl--;
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->y++;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
}

void	leftmouvement(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x - 1] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return ;
	}
	if (game->map->map[game->player->y][game->player->x - 1] == 'E')
	{
		if (game->checks->kolektibl == 0)
			exit (0);
		else if (game->checks->kolektibl > 0)
		{
			ft_putstr("Il te reste des collectibles à ramasser\n");
			return ;
		}
	}
	if (game->map->map[game->player->y][game->player->x - 1] == 'C')
		game->checks->kolektibl--;
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->x--;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
}

void	rightmouvement(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x + 1] == '1')
	{
		ft_putstr("t'es dans lmur fishman\n");
		return ;
	}
	if (game->map->map[game->player->y][game->player->x + 1] == 'E')
	{
		if (game->checks->kolektibl == 0)
			exit (0);
		else if (game->checks->kolektibl > 0)
		{
			ft_putstr("Il te reste des collectibles à ramasser\n");
			return ;
		}
	}
	if (game->map->map[game->player->y][game->player->x + 1] == 'C')
		game->checks->kolektibl--;
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->x++;
	game->map->map[game->player->y][game->player->x] = 'P';
	drawmap(game, game->minilib);
}
