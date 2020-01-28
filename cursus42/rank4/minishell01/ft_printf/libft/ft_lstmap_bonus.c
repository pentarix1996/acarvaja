/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:35:12 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 16:26:42 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *mymap;

	mymap = 0;
	if (lst && f)
	{
		if (!(mymap = ft_lstnew(((*f)(lst->content)))))
			(*del)(lst);
		mymap->next = ft_lstmap(lst->next, f, del);
	}
	return (mymap);
}
