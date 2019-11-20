/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:56:01 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/10 15:38:30 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lowercase(char letter)
{
	int result;

	result = 0;
	if (letter >= 'a' && letter <= 'z')
		result = 1;
	return (result);
}

char	*ft_strupcase(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (is_lowercase(str[counter]) == 1)
		{
			str[counter] -= 32;
		}
		counter++;
	}
	return (str);
}
