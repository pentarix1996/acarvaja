/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:51:43 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/17 17:37:07 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int result;

	if (power < 0)
		return (0);
	result = 1;
	if (power >= 1)
		result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
