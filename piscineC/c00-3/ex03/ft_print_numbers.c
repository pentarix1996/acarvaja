/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:26:51 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/05 18:36:34 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char num;
	char last_digit;

	num = '0';
	last_digit = '9' + 1;
	while (num != last_digit)
	{
		write(1, &num, 1);
		num++;
	}
}
