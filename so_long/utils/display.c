/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:04:17 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 18:06:26 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

void	display_move(t_game *game)
{
	char	*move_count;

	game->player->count++;
	move_count = ft_itoa(game->player->count);
	write(1, "Nombre de mouvements: ", 22);
	write(1, move_count, slong_strlen(move_count));
	write(1, "\n", 1);
	free(move_count);
}

int	spky(t_game *g, int s)
{
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->tile,
		g->player->x * 128, g->player->y * 128);
	g->map->map[g->player->y][g->player->x] = '0';
	g->player->y = g->player->y + s;
	ft_putstr("Il te reste des collectibles à ramasser\n");
	g->map->map[g->player->y][g->player->x] = 'T';
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->fish2,
		g->player->x * 128, g->player->y * 128);
	display_move(g);
	return (1);
}

int	spky2(t_game *g, int s)
{
	g->map->map[g->player->y][g->player->x] = 'E';
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->exit,
		g->player->x * 128, g->player->y * 128);
	g->player->y = g->player->y + s;
	g->map->map[g->player->y][g->player->x] = 'P';
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->fish1,
		g->player->x * 128, g->player->y * 128);
	display_move(g);
	return (1);
}

int	spkx(t_game *g, int s)
{
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->tile,
		g->player->x * 128, g->player->y * 128);
	g->map->map[g->player->y][g->player->x] = '0';
	g->player->x = g->player->x + s;
	ft_putstr("Il te reste des collectibles à ramasser\n");
	g->map->map[g->player->y][g->player->x] = 'T';
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->fish2,
		g->player->x * 128, g->player->y * 128);
	display_move(g);
	return (1);
}

int	spkx2(t_game *g, int s)
{
	g->map->map[g->player->y][g->player->x] = 'E';
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->exit,
		g->player->x * 128, g->player->y * 128);
	g->player->x = g->player->x + s;
	g->map->map[g->player->y][g->player->x] = 'P';
	mlx_put_image_to_window(g->minilib->mlx, g->minilib->win, g->minilib->fish1,
		g->player->x * 128, g->player->y * 128);
	display_move(g);
	return (1);
}
