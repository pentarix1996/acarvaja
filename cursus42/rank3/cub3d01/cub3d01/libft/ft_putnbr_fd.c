/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:43:19 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/13 15:59:56 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n != -2147483648)
	{
		if (n < 10 && n >= 0)
			ft_putchar_fd(n + '0', fd);
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n * -1, fd);
		}
	}
	else
		write(fd, "-2147483648", 11);
}
