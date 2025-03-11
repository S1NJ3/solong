/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawed <jawed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:50:46 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/07 15:16:44 by jawed            ###   ########.fr       */
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
	{
		printf("La carte contient des caractères invalides.\n");
		return (0);
	}
	while (tab[i] != NULL)
	{
		j = slong_strlen(tab[i]);
		if (j != game->checks->mapwidth)
			return (0);
		i++;
	}
	return (1);
}

int	validname(char *map_path)
{
	int	i;

	i = slong_strlen(map_path);
	if (i < 5)
		return (0);
	if (map_path[i - 1] != 'r' || map_path[i - 2] != 'e'
		|| map_path[i - 3] != 'b' || map_path[i - 4] != '.')
		return (0);
	return (1);
}

/*int main(void)
{
    // Exemple de carte (map) pour tester
    char *tab[] = {
        "111111",
        "1C0E01",
        "100P01",
        "1C0001",
        "111111",
        NULL
    };

    // Appel de la fonction validrectangle
    int result = validrectangle(tab);

    // Affichage du résultat
    if (result)
        printf("La carte est un rectangle valide.\n");
    else
        printf("La carte n'est pas un rectangle valide.\n");

    return 0;
}
*/
