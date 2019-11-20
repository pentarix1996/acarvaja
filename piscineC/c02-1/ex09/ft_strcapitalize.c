/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:36:44 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/09 18:07:54 by acarvaja         ###   ########.fr       */
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

int		is_uppercase(char letter)
{
	int result;

	result = 0;
	if (letter >= 'A' && letter <= 'Z')
		result = 1;
	return (result);
}

int		is_number(char letter)
{
	int result;

	result = 0;
	if (letter >= '0' && letter <= '9')
		result = 1;
	return (result);
}

int		is_space(char letter)
{
	int result;

	result = 0;
	if (is_lowercase(letter) == 0 && is_uppercase(letter) == 0)
		if (is_number(letter) == 0)
			result = 1;
	return (result);
}

char	*ft_strcapitalize(char *str)
{
	int counter;
	int space;

	counter = 0;
	space = 1;
	while (str[counter] != '\0')
	{
		if (is_space(str[counter]) == 1)
		{
			space = 1;
			counter++;
			continue;
		}
		if (is_uppercase(str[counter]) == 1)
			str[counter] += 32;
		if (space == 1)
		{
			if (is_lowercase(str[counter]) == 1)
				str[counter] -= 32;
		}
		counter++;
		space = 0;
	}
	return (str);
}
