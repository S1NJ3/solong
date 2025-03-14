/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:02:41 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 17:08:22 by jrighi           ###   ########.fr       */
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
	int		unfree;
}		t_minilib;

typedef struct s_player
{
	int		x;
	int		y;
	int		count;
}			t_player;

typedef struct s_game
{
	struct s_map		*map;
	struct s_char		*checks;
	struct s_minilib	*minilib;
	struct s_player		*player;
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
void	display_move(t_game *game);
void	freeclonemap(t_game *game);
void	freechecks(t_game *game);
char	**fdtotab(char **tab, char *map_path);
int		validname(char *map_path);
void	init_map(t_map *map);
void	init_checks(t_char *checks);
void	mlxinit(t_minilib *minilib, t_game *game);
void	destroyimg(t_minilib *minilib);
void	f2i(void *mlx, void **img, char *path, int *x);
int		key_hook(int touche, t_game *game);
int		upmouvement(t_game *game);
int		downmouvement(t_game *game);
int		leftmouvement(t_game *game);
int		rightmouvement(t_game *game);
void	drawmap(t_game *game, t_minilib *minilib);
void	brexit(t_game *game);
void	freeallgame(t_game *game);
void	freemap(t_game *game);
void	freeminilib(t_game *game);
void	coordassign(t_game *game, int i, int j);
void	free_tab(char **tab, int j);
int		errormsg(char *str);
int		mlxdestroyall(t_game *game);
void	spk(t_game *g);
void	ft_putstr(char *str);
int		spky(t_game *g, int s);
int		spky2(t_game *g, int s);
int		spkx(t_game *g, int s);
int		spkx2(t_game *g, int s);

#endif
