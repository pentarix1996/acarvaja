/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:22 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 20:19:33 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *ptr;

	ptr = dest + ft_strlen(dest);
	while (*src != '\0' && nb--)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
