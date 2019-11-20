/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:21:15 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/12 17:51:08 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		calc_simbol(char simbol)
{
	int result;

	result = 0;
	if (simbol == '-')
		result = 1;
	return (result);
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

int		calc_next_dig(char *str, int i)
{
	int result;

	result = *str++ - '0';
	while (i-- > 0)
		result *= 10;
	return (result);
}

int		calc_numb(char *str)
{
	int result;
	int i;
	int j;

	i = 0;
	result = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	if (i != 0)
	{
		str -= i;
		j = i - 1;
		while (*str != '\0' && *str >= '0' && *str <= '9')
		{
			i = j--;
			result += calc_next_dig(str, i);
			str++;
		}
	}
	return (result);
}

int		ft_atoi(char *str)
{
	int num;
	int simbol;

	num = 0;
	simbol = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while ((*str != '\0' && *str == '+') || (*str != '\0' && *str == '-'))
	{
		simbol += calc_simbol(*str);
		str++;
	}
	if (*str >= '0' && *str <= '9')
	{
		num = calc_numb(str);
		if (simbol % 2 != 0)
			num = num * -1;
	}
	else
		num = 0;
	return (num);
}
