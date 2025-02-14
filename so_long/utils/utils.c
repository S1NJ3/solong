/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:05:07 by jrighi            #+#    #+#             */
/*   Updated: 2025/02/14 18:45:30 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	linewallchek(int i, char **tab)
{
	int	j;

	j = 0;
	while (tab[i][j] != '\0')
	{
		if (tab[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
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

void	gameinit(t_game *game)
{
	//game = malloc(sizeof(t_game));
	game->checks.carapos = 0;
	game->checks.kolektibl = 0;
	game->checks.exitexist = 0;
	game->checks.wallstatus = 0;
	game->checks.koclone = 0;
	game->checks.exitclone = 0;
	game->map.map = NULL;
	game->map.clonemap = NULL;
	game->map.xspawn = 0;
	game->map.yspawn = 0;
	game->map.x = 0;
	game->map.y = 0;
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
