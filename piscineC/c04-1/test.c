/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:19:09 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/18 21:34:25 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* ex00 */
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

/*int main(void)
{
	int tam;
	char str[] = "Hola";
	char *ptr;

	ptr = &str[0];

	tam = ft_strlen(ptr);
	printf("%d", tam);
	return (0);
}*/

/* ex01 */
void	ft_putstr(char *str)
{
	while (str[0] != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

/*int		main(void)
{
	char str[] = "Hola Mundo";
	char *ptr;

	ptr = &str[0];
	ft_putstr(ptr);
	return (0);
}*/

/* ex02 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb != -2147483648)
	{
		if (nb < 10 && nb >= 0)
		{
			ft_putchar(nb + '0');
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
		else
		{
			ft_putchar('-');
			ft_putnbr(nb * -1);
		}
	}
	else
	{
		write(1, "-2147483648", 11);
	}
}

/*int		main(void)
{
	ft_putnbr(-52);
	return (0);
}*/

/* ex03 */
/*int calc_simbol(char simbol)
{
	int result;

	result = 0;
	if (simbol == '-')
		result = 1;
	return (result);
}

int ft_isspace(char space)
{
	int result;
	char *pos_spaces;

	result = 0;
	pos_spaces = " \f\n\r\t\v";
	if(space == *pos_spaces)
		result = 1;
	while (*pos_spaces != '\0' && space != *pos_spaces++)
	{
		if(space == *pos_spaces)
		{
			result = 1;
			break ;
		}
	}
	return (result);
}

int calc_next_dig(char *str, int i)
{
	int result;

	result = *str++ - '0';
	while (i-- > 0)
		result *= 10;
	return (result);
}

int		calc_numb(char *str)
{
	int result;
	int i;
	int j;

	i = 0;
	result = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	if (i != 0)
	{
		str -= i;
		j = i - 1;
		while (*str != '\0' && *str >= '0' && *str <= '9')
		{
			
			i = j--;
			result += calc_next_dig(str, i);
			str++;
		}
	}
	return (result);
}

int ft_atoi(char *str)
{
	int num;
	int simbol;

	num = 0;
	simbol = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while ((*str != '\0' && *str == '+') || (*str != '\0' && *str == '-'))
	{
		simbol += calc_simbol(*str);
		str++;
	}
	if (*str >= '0' && *str <= '9')
	{
		num = calc_numb(str);
		if(simbol % 2 != 0)
			num = num * -1;
	}
	else
		num  = 0;
	return (num);
}*/

/*int main(void)
{
	char *str = "  ---+---+1234ab567";
	//printf("Prueba real: %d\n", atoi("   -032"));
	printf("Mi prueba: %d", ft_atoi(str));
	return (0);
}*/

/* ex04 */
int is_correct_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void print_number(int nbr, char *base)
{
	int numb;
	
	numb = nbr;
	if (nbr == -2147483648)
	{
		print_number(-(nbr / ft_strlen(base)), base);
		print_number(-(nbr % ft_strlen(base)), base);
		return ;
	}
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr >= ft_strlen(base))
	{
		print_number(nbr / ft_strlen(base), base);
		print_number(nbr % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nbr]);
	
}

void ft_putnbr_base(int nbr, char *base)
{
	int lenght;
	unsigned int number;

	if (is_correct_base(base) != 0)
	{
		lenght = ft_strlen(base);
		if (nbr <  0)
			ft_putchar('-');
		number = nbr;		
		print_number(number, base);
	}
}


/*int main(void)
{
	char *base = "01";
	int nbr = -2147483648;
	ft_putnbr_base(nbr, base);
	return (0);
}*/

/* ex05 */
int ft_isspace(char space)
{
	int result;
	char *pos_spaces;

	result = 0;
	pos_spaces = " \f\n\r\t\v";
	if(space == *pos_spaces)
		result = 1;
	while (*pos_spaces != '\0' && space != *pos_spaces++)
	{
		if(space == *pos_spaces)
		{
			result = 1;
			break ;
		}
	}
	return (result);
}

int nmb_on_base(char letter, char *base)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (base[i] != '\0')
	{
		if (letter == base[i++])
		{
			flag = 1;
			break ;
		}
	}

	return (flag);
}

int	calc_basenbr(char *base, char nbrb, int pos)
{
	int i;
	int result;
	int number;
	int lenght;

	i = -1;
	lenght = 0;
	while (base[++i] != '\0')
		lenght++;
	result = 0;
	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == nbrb)
		{
			number = i;
			while (pos > 1)
			{
				number *= lenght;
				pos--;
			}
			result += number;
		}
	}
	return (result);
}

int ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int number;
	int simbol;

	if (is_correct_base(base) == 0)
		return (0);
	number = 0;
	simbol = 0;
	while (ft_isspace(*str) == 1)
		str++;
	while ((*str != '\0' && *str == '+') || (*str != '\0' && *str == '-'))
		*str++ == '-' ? simbol++ : simbol;
	i = 0;
	while (str[i] != '\0' && nmb_on_base(str[i], base) == 1)
		i++;
	j = 0;
	while (str[j] != '\0' && nmb_on_base(str[j], base) == 1)
	{
		number += calc_basenbr(base, str[j], i - j);
		if (++j > 10)
			return (0);
	}
	simbol % 2 != 0 ? number = number * -1 : 0;
	return (number);
}

/*int main(void)
{
	char *base = "0123";
	char *str = "   \t  \v \n\r\f +++--+012121";
	printf("%d", ft_atoi_base(str, base));
	return (0);
}*/