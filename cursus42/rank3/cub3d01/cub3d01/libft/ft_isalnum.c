/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:38:15 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/12 14:22:06 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c) ? 1 : 0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int			ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c) ? 1 : 0);
}
