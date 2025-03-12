/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:05:07 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/12 12:27:00 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

void	coordassign(t_game *game, int i, int j)
{
	game->map->yspawn = i;
	game->map->xspawn = j;
	game->player->y = i;
	game->player->x = j;
}

int	errormsg(char *str)
{
	write(1, str, slong_strlen(str));
	return (0);
}

int	slong_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	slong_mapheight(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return (i);
}

char	**mapcopy(char **map)
{
	int		i;
	char	**clonemap;

	i = 0;
	clonemap = malloc(sizeof(char *) * (slong_mapheight(map) + 1));
	if (clonemap == NULL)
		return (0);
	while (map[i] != NULL)
	{
		clonemap[i] = ft_strdup(map[i]);
		i++;
	}
	clonemap[i] = NULL;
	return (clonemap);
}
