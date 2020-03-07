/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:50:34 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/13 16:52:35 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int asc)
{
	return (asc == 32 || asc == '\t' || asc == '\n' ||
				asc == '\v' || asc == '\f' || asc == '\r');
}
