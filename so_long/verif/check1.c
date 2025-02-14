/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:29:47 by jrighi            #+#    #+#             */
/*   Updated: 2025/02/14 18:56:02 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	kolektichek(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] == 'C')
				game->checks.kolektibl++;
			j++;
		}
		i++;
	}
	if (game->checks.kolektibl < 1)
		return (0);
	else if (game->checks.kolektibl >= 1)
	{
		game->checks.koclone = game->checks.kolektibl;
		return (game->checks.kolektibl);
	}
}

int	spawnchek(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] == 'P')
			{
				game->checks.carapos++;
				game->map.yspawn = i;
				game->map.xspawn = j;
			}
			j++;
		}
		i++;
	}
	if (game->checks.carapos != 1)
		return (0);
	else if (game->checks.carapos == 1)
		return (1);
}

int	exichek(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] == 'E')
				game->checks.exitexist++;
			j++;
		}
		i++;
	}
	game->checks.exitclone = game->checks.exitexist;
	if (game->checks.exitexist != 1)
		return (0);
	else if (game->checks.exitexist == 1)
		return (1);
}

int	wallchek(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	game->checks.wallstatus = 0;
	while (game->map.map[k] != NULL)
		k++;
	while (game->map.map[i][j] != '\0')
		j++;
	if (linewallchek(0, game->map.map) == 0)
		return (0);
	i++;
	while (i < k - 1)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][j - 1] != '1')
			return (0);
		i++;
	}
	if (linewallchek(i, game->map.map) == 0)
		return (0);
	game->checks.wallstatus = 1;
	return (1);
}


int	allchecks(t_game *game)
{
	if (kolektichek(game) && exichek(game)
		&& wallchek(game) && spawnchek(game)
		&& validrectangle(game->map.map))
	{
		return (1);
	}
	return (0);
}

/*int allchecks(struct s_char checks, char **tab)
{
    int result = 1;

    if (!kolektichek(checks.kolektibl, tab))
    {
        printf("Check des collectibles échoué.\n");
        result = 0;
    }
    else
    {
        printf("Check des collectibles réussi.\n");
    }

    if (!exichek(checks.exitexist, tab))
    {
        printf("Check des exits échoué.\n");
        result = 0;
    }
    else
    {
        printf("Check des exits réussi.\n");
    }

    if (!wallchek(checks.wallstatus, tab))
    {
        printf("Check des murs échoué.\n");
        result = 0;
    }
    else
    {
        printf("Check des murs réussi.\n");
    }

    if (!spawnchek(checks.carapos, tab))
    {
        printf("Check des spawns échoué.\n");
        result = 0;
    }
    else
    {
        printf("Check des spawns réussi.\n");
    }
	if (!validrectangle(tab))
	{
		printf("Check des rectangles échoué.\n");
		result = 0;
	}
	else
	{
		printf("Check des rectangles réussi.\n");
	}

    return result;
}*/

/*int main(void)
{
    // Exemple de tableau de carte (map) pour tester
    char *tab[] = {
        "111111",
        "1C00P1",
        "100001",
        "1C1E01",
        "111111",
        NULL
    };

    // Initialisation de la structure t_game
    t_game game;
    game.checks.kolektibl = 0;
    game.checks.exitexist = 0;
    game.checks.wallstatus = 0;
    game.checks.carapos = 0;
    game.map.map = tab;
	game.map.xspawn = 0; // Initialisation de xspawn
    game.map.yspawn = 0; // Initialisation de yspawn

    // Appel de la fonction allchecks
    int result = allchecks(&game);
    printf("kolektibl: %d\n", game.checks.kolektibl);
	printf("exit: %d\n", game.checks.exitexist);
	printf("wallstatus: %d\n", game.checks.wallstatus);
	printf("spawnexist: %d\n", game.checks.carapos);
	printf("xspawn: %d\n", game.map.xspawn);
	printf("yspawn: %d\n", game.map.yspawn);

    // Affichage du résultat global
    if (result)
        printf("Tous les checks sont corrects.\n");
    else
        printf("Un ou plusieurs checks ne sont pas corrects.\n");

    return 0;
}*/

