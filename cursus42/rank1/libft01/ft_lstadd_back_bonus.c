/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:59:51 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/12 02:54:38 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*aux;

	aux = ft_lstlast(*alst);
	if (alst && new)
	{
		if (*alst == NULL)
		{
			*alst = new;
			new->next = NULL;
		}
		else
		{
			aux->next = new;
			new->next = NULL;
		}
	}
}
