/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapverif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:28:57 by jrighi            #+#    #+#             */
/*   Updated: 2025/01/24 17:05:44 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	fdlen(const char *map_path)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	c = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) == 1)
	{
		i++;
	}
	close(fd);
	printf("la taille de la map est %d\n", i);
	return (i);
}

char	**fdtotab(char **tab, const char *map_path)
{
	int	i;
	int fd;

	i = (fdlen(map_path));
	tab = malloc(sizeof(char) * (i + 1));
	fd = open(map_path, O_RDONLY);
	if (tab == NULL)
		return (0);
	while ((tab[i] = get_next_line(fd)) != NULL)
	{
		printf("%s",tab[i]);
		i++;
	}
	return (tab);
}

int main(int argc, char **argv)
{
	char **tab = NULL;
    if (argc != 2)
    {
        printf("Usage: %s <chemin_de_la_map>\n", argv[0]);
        return 1;
    }
	fdtotab(tab, argv[1]);
    return 0;
}
