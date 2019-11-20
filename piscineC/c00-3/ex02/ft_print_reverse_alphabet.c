/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:19:26 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/05 18:23:45 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char alf;
	char last_char;

	alf = 'z';
	last_char = 'a' - 1;
	while (alf != last_char)
	{
		write(1, &alf, 1);
		alf--;
	}
}
