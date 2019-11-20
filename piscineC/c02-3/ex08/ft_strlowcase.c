/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:07:44 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/09 16:08:26 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_uppercase(char letter)
{
	int result;

	result = 0;
	if (letter >= 'A' && letter <= 'Z')
		result = 1;
	return (result);
}

char	*ft_strlowcase(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (is_uppercase(str[counter]) == 1)
		{
			str[counter] += 32;
		}
		counter++;
	}
	return (str);
}
