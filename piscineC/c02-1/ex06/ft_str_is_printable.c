/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:53:57 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/08 21:54:11 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if (str[0] == '\0')
		result = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
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
