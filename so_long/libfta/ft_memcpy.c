/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:18:47 by jrighi            #+#    #+#             */
/*   Updated: 2024/10/03 16:29:00 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char	*str;
	char	*scr;
	int		i;

	i = 0;
	str = (char *)dest;
	scr = (char *)src;
	if (!src && !dest)
		return (dest);
	while (n)
	{
		str[i] = scr[i];
		i++;
		n--;
	}
	return (dest);
}
