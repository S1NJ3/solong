/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:36:25 by jrighi            #+#    #+#             */
/*   Updated: 2024/10/09 16:17:37 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	hay = (char *)str;
	if (to_find[0] == '\0')
		return (hay);
	while (hay[i] && i < n)
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j]
			&& i + j < n)
			j++;
		if (to_find[j] == '\0')
			return (hay + i);
		i++;
	}
	return (0);
}
