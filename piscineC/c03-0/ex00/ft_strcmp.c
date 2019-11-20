/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:15:22 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/10 20:17:41 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int result;
	int	cmp1;
	int i;

	i = 0;
	cmp1 = 0;
	result = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		result += s1[i];
		cmp1 += s2[i];
		if ((result - cmp1) < 0)
			break ;
		else if ((result - cmp1) > 0)
			break ;
		i++;
	}
	result -= cmp1;
	return (result);
}
