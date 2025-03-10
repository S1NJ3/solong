/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:02:41 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/05 18:34:00 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_char
{
	int		carapos;
	int		kolektibl;
	int		exitexist;
	int		wallstatus;
	int		koclone;
	int		exitclone;
	int		exx;
	int		exy;
	int		mapwidth;
	int		mapheight;
}			t_char;

typedef struct s_map
{
	char	**map;
	char	**clonemap;
	int		xspawn;
	int		yspawn;
	int		x;
	int		y;
}			t_map;

typedef struct s_minilib
{
	void	*mlx;
	void	*win;
	void	*tile;
	void	*fish1;
	void	*fish2;
	void	*kolek;
	void	*exit;
	void	*wall;
	int		*height;
}		t_minilib;

typedef struct s_game
{
	struct s_map		*map;
	struct s_char		*checks;
	struct s_minilib	*minilib;
}			t_game;

int		linewallchek(int i, char **tab);
int		slong_strlen(char *str);
int		validrectangle(char **tab, t_game *game);
int		kolektichek(t_game *game);
int		spawnchek(t_game *game);
int		exichek(t_game	*game);
int		wallchek(t_game *game);
int		allchecks(t_game *game);
int		validcara(char **tab);
int		slong_mapheight(char **tab);
char	**mapcopy(char **map);
void	gameinit(t_game *game);
int		validpath(t_game *game);
int		flood_fill(t_game *game, int x, int y);
void	floodcount(t_game *game, int x, int y);
int		flooderrorchek(t_game *game, int x, int y);
int		fdlen(char *map_path);
char	**fdtotab(char **tab, char *map_path);
int		validname(char *map_path);
void	init_map(t_map *map);
void	init_checks(t_char *checks);
void	freeallgame(t_game *game);
void	mlxinit(t_minilib *minilib);
void	destroyimg(t_minilib *minilib);
void	f2i(void *mlx, void **img, char *path, int *x);
int		key_hook(int touche, t_game *game);
void	upmouvement(t_game *game);
void	downmouvement(t_game *game);
void	leftmouvement(t_game *game);
void	rightmouvement(t_game *game);




#endif
