/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:08:33 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 18:08:33 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	f2i(void *mlx, void **image, char *path, int *x)
{
	*image = mlx_xpm_file_to_image(mlx, path, x, x);
}

void	destroyimg(t_minilib *minilib)
{
	mlx_destroy_image(minilib->mlx, minilib->tile);
	mlx_destroy_image(minilib->mlx, minilib->kolek);
	mlx_destroy_image(minilib->mlx, minilib->exit);
	mlx_destroy_image(minilib->mlx, minilib->wall);
	mlx_destroy_image(minilib->mlx, minilib->fish1);
	mlx_destroy_image(minilib->mlx, minilib->fish2);
}

int	key_hook(int touche, t_game *game)
{
	if (touche == 65307 || touche == 113)
		brexit(game);
	if (touche == 119)
		upmouvement(game);
	if (touche == 115)
		downmouvement(game);
	if (touche == 97)
		leftmouvement(game);
	if (touche == 100)
		rightmouvement(game);
	return (0);
}

void	drawmap(t_game *g, t_minilib *m)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	p = 128;
	while (y < g->checks->mapheight)
	{
		x = 0;
		while (x < g->checks->mapwidth)
		{
			if (g->map->map[y][x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->wall, x * p, y * p);
			if (g->map->map[y][x] == '0')
				mlx_put_image_to_window(m->mlx, m->win, m->tile, x * p, y * p);
			if (g->map->map[y][x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->kolek, x * p, y * p);
			if (g->map->map[y][x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->exit, x * p, y * p);
			if (g->map->map[y][x] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->fish1, x * p, y * p);
			x++;
		}
		y++;
	}
}

void	mlxinit(t_minilib *minilib, t_game *game)
{
	int	height;
	int	x;
	int	y;

	x = game->checks->mapwidth - 1;
	y = game->checks->mapheight;
	if (x > 127 || y > 127)
	{
		printf("Error: map trop grande.\n");
		brexit(game);
	}
	minilib->mlx = mlx_init();
	minilib->unfree = 1;
	minilib->win = mlx_new_window(minilib->mlx, ((x) * 128),
			((y) * 128), "so_long");
	height = 128;
	f2i(minilib->mlx, &minilib->tile, "img/sand.xpm", &height);
	f2i(minilib->mlx, &minilib->kolek, "img/kolek.xpm", &height);
	f2i(minilib->mlx, &minilib->exit, "img/sortie.xpm", &height);
	f2i(minilib->mlx, &minilib->wall, "img/murs.xpm", &height);
	f2i(minilib->mlx, &minilib->fish1, "img/fish1.xpm", &height);
	f2i(minilib->mlx, &minilib->fish2, "img/fish2.xpm", &height);
	drawmap(game, game->minilib);
}
