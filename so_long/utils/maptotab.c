/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptotab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:28:57 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/05 17:23:43 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibi/so_long.h"

int	fdlen(char *map_path)
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
	return (i);
}

int	fdheight(char *map_path)
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
		if (c == '\n')
			i++;
	}
	close(fd);
	return (i);
}

char	**fdtotab(char **tab, char *map_path)
{
	int	i;
	int	fd;
	int	j;

	i = (fdlen(map_path));
	tab = malloc(sizeof(char *) * (i + 1));
	fd = open(map_path, O_RDONLY);
	i = fdheight(map_path);
	j = 0;
	if (tab == NULL)
		return (0);
	while (j < i)
	{
		tab[j] = get_next_line(fd);
		j++;
	}
	return (tab);
}




/*int main(int argc, char **argv)
{
	char **tab = NULL;
    if (argc != 2)
    {
        printf("Usage: %s <chemin_de_la_map>\n", argv[0]);
        return 1;
    }
	fdtotab(tab, argv[1]);
    return 0;
}*/
