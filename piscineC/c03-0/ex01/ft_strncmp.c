/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:27:23 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/10 20:37:49 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				result;
	int				cmp1;
	unsigned int	i;

	i = 0;
	cmp1 = 0;
	result = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
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
