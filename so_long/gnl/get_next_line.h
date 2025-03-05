/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42Lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:24:42 by jrighi            #+#    #+#             */
/*   Updated: 2025/03/05 17:24:38 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*gnl_strjoin(char const *s1, char const *s2);
int		gnl_strachr(const char *str, int c);
char	*extract_line1(char *stash, int i);
char	*extract_line2(char *stash);
char	*extract_line(char *stash);
char	*read_to_stash(int fd, char *stash);
int		gnl_strlen(const char *str);
char	*get_next_line(int fd);

#endif
