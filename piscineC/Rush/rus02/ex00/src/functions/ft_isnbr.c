/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:57:38 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:35:19 by avaldes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnbr(char *str)
{
	int		cont0;
	int		contn;

	cont = 0;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		else
		{
			if (*str == '0')
				cont0++;
			else
			{
				if (cont0 > 0 && contn = 0)
					return (0);
				contn++;
			}
		}
		str++;
	}
	return (1);
}
