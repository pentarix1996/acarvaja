/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:20:52 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 13:23:26 by acarvaja         ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (ft_strcmp(&to_find[j], &str[i + j]) == 0)
		{
			if (to_find[j] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
