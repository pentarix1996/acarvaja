/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:20:52 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 20:03:09 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		compare(char *dest, char *src)
{
	while (*dest && *src)
	{
		if (*dest != *src)
			return (0);
		dest++;
		src++;
	}
	return (*src == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
