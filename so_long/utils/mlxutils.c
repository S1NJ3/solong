/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:08:33 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/05 18:33:20 by jrighi           ###   ########.fr       */
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
	{
		destroyimg(game->minilib);
		mlx_destroy_window(game->minilib->mlx, game->minilib->win);
		freeallgame(game);
		exit(0);
	}
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

void	mlxinit(t_minilib *minilib)
{
	int	height;

	minilib->mlx = mlx_init();
	minilib->win = mlx_new_window(minilib->mlx, 800, 600, "so_long");
	height = 64;
	f2i(minilib->mlx, &minilib->tile, "img/sand.xpm", &height);
	f2i(minilib->mlx, &minilib->kolek, "img/kolek.xpm", &height);
	f2i(minilib->mlx, &minilib->exit, "img/sortie.xpm", &height);
	f2i(minilib->mlx, &minilib->wall, "img/murs.xpm", &height);
	f2i(minilib->mlx, &minilib->fish1, "img/fish1.xpm", &height);
	f2i(minilib->mlx, &minilib->fish2, "img/kolek.xpm", &height);
}
