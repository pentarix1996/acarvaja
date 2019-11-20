/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:19:46 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 20:20:28 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = ft_strlen(src);
	while (*dest && size > 0 && size--)
	{
		dest++;
		i++;
	}
	while (*src && size > 1 && size--)
		*dest++ = *src++;
	if (size == 1)
		*dest = '\0';
	return (j + i);
}
