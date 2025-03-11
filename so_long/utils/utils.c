/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawed <jawed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:05:07 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/07 15:19:44 by jawed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"



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

void	freeallgame(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i] != NULL)
	{
		free(game->map->map[i]);
		i++;
	}
	free(game->map->map);
	free(game->map->clonemap);
	free(game->map);
	free(game->checks);
	free(game->player);
	free(game);
}

void	brexit(t_game *game)
{
	freeallgame(game);
	exit (0);
}

/*int main(void)
{
    // Exemple de tableau de carte (map) pour tester
    char *map[] = {
        "111111",
        "1ZIZI1",
        "100111",
        "1C1E01",
        "111111",
        NULL
    };

    // Appel de la fonction mapcopy
    char **clonemap = mapcopy(map);

    // Affichage de la carte copiée
    if (clonemap != NULL)
    {
        int i = 0;
        while (clonemap[i] != NULL)
        {
            printf("%s\n", clonemap[i]);
            i++;
        }
    }
    else
    {
        printf("Erreur lors de la copie de la carte.\n");
    }

    // Libération de la mémoire allouée pour la carte copiée
    int i = 0;
    while (clonemap[i] != NULL)
    {
        free(clonemap[i]);
        i++;
    }
    free(clonemap);

    return 0;
}*/
