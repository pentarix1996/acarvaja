/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:30:55 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/18 19:55:16 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_correct_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_isspace(char space)
{
	int		result;
	char	*pos_spaces;

	result = 0;
	pos_spaces = " \f\n\r\t\v";
	if (space == *pos_spaces)
		result = 1;
	while (*pos_spaces != '\0' && space != *pos_spaces++)
	{
		if (space == *pos_spaces)
		{
			result = 1;
			break ;
		}
	}
	return (result);
}

int		nmb_on_base(char letter, char *base)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (base[i] != '\0')
	{
		if (letter == base[i++])
		{
			flag = 1;
			break ;
		}
	}
	return (flag);
}

int		calc_basenbr(char *base, char nbrb, int pos)
{
	int i;
	int result;
	int number;
	int lenght;

	i = -1;
	lenght = 0;
	while (base[++i] != '\0')
		lenght++;
	result = 0;
	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == nbrb)
		{
			number = i;
			while (pos > 1)
			{
				number *= lenght;
				pos--;
			}
			result += number;
		}
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int number;
	int simbol;

	if (is_correct_base(base) == 0)
		return (0);
	number = 0;
	simbol = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while ((*str != '\0' && *str == '+') || (*str != '\0' && *str == '-'))
		*str++ == '-' ? simbol++ : simbol;
	i = 0;
	while (str[i] != '\0' && nmb_on_base(str[i], base) == 1)
		i++;
	j = 0;
	while (str[j] != '\0' && nmb_on_base(str[j], base) == 1)
	{
		number += calc_basenbr(base, str[j], i - j);
		if (++j > 10)
			return (0);
	}
	simbol % 2 != 0 ? number = number * -1 : 0;
	return (number);
}
