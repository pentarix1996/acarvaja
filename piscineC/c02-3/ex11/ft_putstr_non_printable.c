/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:11:38 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 17:30:23 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex_converter(char *hex, unsigned char c)
{
	hex[0] = 92;
	if (c / 16 <= 9)
		hex[1] = c / 16 + 48;
	else
		hex[1] = c / 16 + 87;
	if (c % 16 <= 9)
		hex[2] = c % 16 + 48;
	else
		hex[2] = c % 16 + 87;
	hex[3] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		j;
	char	hex[4];
	char	*ptr;

	i = 0;
	j = 0;
	hex[0] = '\0';
	ptr = &hex[0];
	while (str[i] != '\0')
	{
		if (str[i] > 126 || str[i] < 32)
		{
			ft_hex_converter(ptr, (unsigned char)str[i]);
			while (j < 3)
			{
				ft_putchar(hex[j]);
				j++;
			}
			j = 0;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
