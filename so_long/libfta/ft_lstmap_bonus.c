/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrighi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:59:09 by jrighi            #+#    #+#             */
/*   Updated: 2024/10/09 15:25:28 by jrighi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*final;
	t_list	*elem;

	final = NULL;
	while (lst)
	{
		elem = malloc(sizeof(t_list));
		if (!elem)
		{
			ft_lstclear(&final, del);
			return (NULL);
		}
		elem -> content = f(lst ->content);
		elem -> next = NULL;
		ft_lstadd_back(&final, elem);
		lst = lst -> next;
	}
	return (final);
}
