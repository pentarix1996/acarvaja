/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:05:32 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/16 18:05:45 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int fibbo;

	fibbo = 0;
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	else
		fibbo += ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (fibbo);
}
