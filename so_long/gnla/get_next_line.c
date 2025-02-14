/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:34:33 by jrighi            #+#    #+#             */
/*   Updated: 2025/02/14 18:22:10 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = extract_line1(stash, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_to_stash(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	lu;

	lu = 1;
	while ((gnl_strachr(stash, '\n') == 0) && (lu > 0))
	{
		lu = read(fd, buffer, BUFFER_SIZE);
		if (lu < 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[lu] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 999)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || !*stash)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = extract_line2(stash);
	if (!line || *line == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}
