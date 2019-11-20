/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:15:22 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/16 13:12:46 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

int				ft_strcmp(char *s1, char *s2)
{
	int				result;
	int				cmp1;
	unsigned	int	i;

	i = 0;
	cmp1 = 0;
	result = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i < ft_strlen(s1))
			result += (unsigned char)s1[i];
		if (i < ft_strlen(s2))
			cmp1 += (unsigned char)s2[i];
		if ((result - cmp1) < 0)
			break ;
		else if ((result - cmp1) > 0)
			break ;
		i++;
	}
	result -= cmp1;
	return (result);
}
