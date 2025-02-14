/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:02:41 by jrighi            #+#    #+#             */
/*   Updated: 2025/02/14 18:28:43 by jrighi           ###   ########.fr       */
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

typedef struct s_game
{
	struct s_map	map;
	struct s_char	checks;
}			t_game;

int		linewallchek(int i, char **tab);
int		slong_strlen(char *str);
int		validrectangle(char **tab);
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
void	flood_fill(t_game *game, int x, int y);
void	floodcount(t_game *game, int x, int y);
int		flooderrorchek(t_game *game, int x, int y);
int		fdlen(const char *map_path);
char	**fdtotab(char **tab, const char *map_path);





#endif
