/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:50:46 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/14 17:18:14 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	linewallchek(int i, char **tab)
{
	int	j;

	j = 0;
	while (tab[i][j] != '\n')
	{
		if (tab[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	validcara(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != 'P' && tab[i][j] != 'E' && tab[i][j] != 'C'
				&& tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != '\n'
				&& tab[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validrectangle(char **tab, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->checks->mapwidth = slong_strlen(tab[0]);
	game->checks->mapheight = slong_mapheight(tab);
	if (validcara(tab) == 0)
		return (errormsg("Error: caractères invalides.\n"));
	while (tab[i] != NULL)
	{
		j = slong_strlen(tab[i]);
		if (j != game->checks->mapwidth)
			return (errormsg("Error: forme de map invalide.\n"));
		i++;
	}
	return (1);
}

int	validname(char *map_path)
{
	int	i;

	i = slong_strlen(map_path);
	if (i < 5)
		return (errormsg("Error: nom de fichier invalide.\n"));
	if (map_path[i - 1] != 'r' || map_path[i - 2] != 'e'
		|| map_path[i - 3] != 'b' || map_path[i - 4] != '.')
		return (errormsg("Error: nom de fichier invalide.\n"));
	return (1);
}
