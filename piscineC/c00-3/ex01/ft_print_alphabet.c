/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:54:38 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/05 15:56:15 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char alf;
	char last_char;

	alf = 'a';
	last_char = 'z' + 1;
	while (alf != last_char)
	{
		write(1, &alf, 1);
		alf++;
	}
}
