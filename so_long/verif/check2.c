/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:50:46 by jrighi            #+#    #+#             */
/*   Updated: 2025/02/12 20:11:17 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

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

int	validrectangle(char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = slong_strlen(tab[0]);
	if (validcara(tab) == 0)
	{
		printf("La carte contient des caractères invalides.\n");
		return (0);
	}
	while (tab[i] != NULL)
	{
		j = slong_strlen(tab[i]);
		if (j != len)
			return (0);
		i++;
	}
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
