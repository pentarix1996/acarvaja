/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:41:12 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/08 21:41:54 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if (str[0] == '\0')
		result = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = 1;
		else
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}
