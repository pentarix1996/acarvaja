/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_tunned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:02:57 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 11:29:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			compare(char *dest, char *src);

int			ft_strstr_tunned(char *str, char *to_find)
{
	int i;

	i = 0;
	if (*to_find == '\0')
		return (i);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (i);
		str++;
		i++;
	}
	return (0);
}
