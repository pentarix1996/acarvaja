/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:43:02 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/17 17:35:42 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		i;
	int		div;

	if (nb <= 1)
		return (0);
	i = 2;
	div = 0;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			div++;
		if (div >= 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		while (ft_is_prime(nb) != 1)
			nb++;
	return (nb);
}
