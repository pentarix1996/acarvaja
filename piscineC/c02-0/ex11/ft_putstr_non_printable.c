/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:11:38 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/10 18:27:23 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char put)
{
	write(1, &put, 1);
}

int		is_special(char letter)
{
	int result;

	result = 0;
	if (letter < ' ' || letter > '~')
		result = 1;
	return (result);
}

void	special_write(int letter)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	ft_putchar('\\');
	if (letter < 16)
	{
		ft_putchar('0');
	}
	while (letter > 0)
	{
		ft_putchar(hexa[letter % 16]);
		letter /= 16;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_special(str[i]) == 1)
			special_write(str[i] - '\0');
		else
			ft_putchar(str[i]);
		i++;
	}
}
