/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:30:52 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 17:23:28 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				c;

	i = 0;
	c = 0;
	while (src[i] != '\0')
	{
		c++;
		i++;
	}
	i = 0;
	while (i < size - 1 && size > 0)
	{
		if (src[i] == '\0')
		{
			dest[i] = src[i];
			return (c);
		}
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (c);
}
