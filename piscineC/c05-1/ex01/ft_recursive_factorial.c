/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:32:28 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/16 17:37:31 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int fact;

	fact = 1;
	if (nb < 0)
		return (0);
	if (nb > 1)
		fact = nb * ft_recursive_factorial(nb - 1);
	return (fact);
}
