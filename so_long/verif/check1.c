/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <jrighi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:29:47 by jrighi            #+#    #+#             */
/*   Updated: 2025/01/24 15:54:47 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	allchecks(int kolektibl, int exitexist, bool wallcheck, int carapos)

{
	if (kolektibl >= 1)
		return (1);
	else
	{
		write (1, "error\n collectibles bug\n", 25);
		return (0);
	}
	if (exitexist == 1)
		return (1);
	else
	{
		write (1, "error\n exit bug\n", 18);
		return (0);
	}
	if (wallcheck == 1)
		return (1);
	else
	{
		write (1, "error\n not walled\n", 19);
		return (0);
	}
	if (carapos == 1)
		return (1);
	else
	{
		write (1, "error\n more or less than 1 spawn\n", 34);
		return (0);
	}
}

/*int main(void)
{
	int kolektibl = 1;
	int exitexist = 1;
	bool wallcheck = 1;
	int	carapos = 1;

	allchecks(kolektibl,exitexist,wallcheck,carapos);
}
*/
