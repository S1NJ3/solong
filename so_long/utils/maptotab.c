/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptotab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:28:57 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/12 12:41:27 by jrighi           ###   ########.fr       */
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

void	free_tab(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
}

char	**fdtotab(char **tab, char *map_path)
{
	int	i;
	int	fd;
	int	j;

	i = fdheight(map_path);
	tab = malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (free(tab), NULL);
	j = 0;
	while (j < i)
	{
		tab[j] = get_next_line(fd);
		if (tab[j] == NULL)
			return (free_tab(tab, j), close(fd), NULL);
		j++;
	}
	tab[j] = NULL;
	close(fd);
	return (tab);
}
