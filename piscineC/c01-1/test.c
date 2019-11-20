/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:38:18 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/08 19:38:05 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_putint(int *x)
{
	printf("%d", *x);
}

/* ex00 */
void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*int main(void)
{
	int x;
	int *ptr;

	ptr = &x;
	ft_ft(ptr);
	ft_putint(ptr);
}*/

/* ex01 */
void ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*int main(void)
{
	int x;
	int *ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;
	int *********ptr9;

	ptr1 = &x;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	ft_ultimate_ft(ptr9);
	printf("%d", *********ptr9);
}*/
/* ex02 */
void ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*int		main(void)
{
	int *numb1;
	int *numb2;
	int x;
	int y;

	y = 1;
	numb1 = &y;
	x = 7;
	numb2 = &x;
	ft_putint(numb1);
	ft_putint(numb2);
	ft_swap(numb1, numb2);
	ft_putint(numb1);
	ft_putint(numb2);
	return (0);
}*/

/* ex03 */
void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int		main(void)
{
	int *div;
	int *mod;
	int a;
	int b;

	a = 3;
	b = 4;
	div = &a;
	mod = &b;
	ft_div_mod(a, b, div, mod);
	ft_putint(div);
	ft_putint(mod);
	return (0);
}*/

/* ex04 */
void ft_ultimate_div_mod(int *a, int *b)
{
	int div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}

/*int		main(void)
{
	int *div;
	int *mod;
	int a;
	int b;

	a = 20;
	b = 5;
	div = &a;
	mod = &b;
	ft_ultimate_div_mod(div, mod);
	ft_putint(div);
	ft_putint(mod);
	return (0);
}*/

/* ex05*/
void ft_putstr(char *str)
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

/* ex06 */
int ft_strlen(char *str)
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

/* ex07 */
void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = size - 1;
	while (i != size/2)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}

/*int main(void)
{
	int size = 3;
	int nums[size];
	char x;
	
	x = '-';
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	int i = 0;
	while (i < size)
	{
		printf("%d", nums[i]);
		i++;
	}

	ft_rev_int_tab(nums, size);
	printf("%c", x);

	i = 0;
	while (i < size)
	{
		printf("%d", nums[i]);
		i++;
	}
	return (0);
}*/

/* ex08 */
void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0)
		{
			if (tab[j] < tab[j - 1])
			{
				ft_swap(&tab[j], &tab[j - 1]);
			}
			j--;
		}
		i++;
	}
}

/*int main(void)
{
	int size = 5;
	int nums[size];
	char x;
	
	x = ' ';
	nums[0] = 7;
	nums[1] = 3;
	nums[2] = 1;
	nums[3] = 1;
	nums[4] = 2;
	int i = 0;
	while (i < size)
	{
		printf("%d", nums[i]);
		i++;
	}

	ft_sort_int_tab(nums, size);
	printf("%c", x);

	i = 0;
	while (i < size)
	{
		printf("%d", nums[i]);
		i++;
	}
	return (0);
}*/