/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:33:04 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/08 21:36:47 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if (str[0] == '\0')
		result = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			result = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
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
