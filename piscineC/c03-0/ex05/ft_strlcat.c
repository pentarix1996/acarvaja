/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:19:46 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 13:22:22 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	length_str(char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;
	unsigned int comp;

	if (length_str(dest) <= size)
		result = length_str(dest) + length_str(src);
	else
		result = length_str(src) + length_str(dest) - (length_str(dest) - size);
	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	if (size == 0)
		comp = size;
	else
		comp = size - 1;
	while (src[i] != '\0' && (j + i) < comp)
	{
		dest[j + i] = src[i];
		i++;
	}
	return (result);
}
