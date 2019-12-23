/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:31:58 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 12:51:52 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int cont;

	cont = 0;
	if (lst)
	{
		cont++;
		while ((*lst).next)
		{
			lst = (*lst).next;
			cont++;
		}
	}
	return (cont);
}
