/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:37:55 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 18:54:48 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* ex00 */
char *ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main(void)
{
	char str[] = "Hello world";
	char str2[] = "Hola grande";

	printf("%s", strcpy(str, str2));
	printf(" <--> ");
	printf("%s", ft_strcpy(str ,str2));
	return (0);
}*/

/* ex01 */
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int main(void)
{
	char dest[] = "BcaA";
	char src[] = "Abc";
	
	printf("%s", strncpy(dest, src, sizeof(dest)));
	printf("%s", ft_strncpy(dest ,src, sizeof(dest)));
	return (0);
}*/

/* ex02 */
int		ft_str_is_alpha(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if (str[0] == '\0')
		result = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			result = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result = 1;
		else
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

/*int main(void)
{
	char str[] = "HoL2a";
	
	printf("resultado: %d", ft_str_is_alpha(str));
	return (0);
}*/

/* ex03 */
int ft_str_is_numeric(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if(str[0] == '\0')
		result = 1;
	while(str[i] != '\0')
	{
		if(str[i] >= '0' && str[i] <= '9')
			result = 1;
		else
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

/*int main(void)
{
	char str[] = "";
	
	printf("resultado: %d", ft_str_is_numeric(str));
	return (0);
}*/

/* ex04 */
int ft_str_is_lowercase(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if(str[0] == '\0')
		result = 1;
	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			result = 1;
		else
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

/*int main(void)
{
	char str[] = "cuarentaydos";
	
	printf("resultado: %d", ft_str_is_lowercase(str));
	return (0);
}*/

/* ex05 */
int ft_str_is_uppercase(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if(str[0] == '\0')
		result = 1;
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			result = 1;
		else
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

/*int main(void)
{
	char str[] = "AZAZAZS";
	
	printf("resultado: %d", ft_str_is_uppercase(str));
	return (0);
}*/

/* ex06 */
int ft_str_is_printable(char *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	if(str[0] == '\0')
		result = 1;
	while(str[i] != '\0')
	{
		if(str[i] >= ' ' && str[i] <= '~')
			result = 1;
		else
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

/*int main(void)
{
	char str[] = "\t\n";
	char str2[] = "Este deberia dar 1:$$$+*`";
	
	printf("resultado prueba 0: %d", ft_str_is_printable(str));
	printf("resultado prueba 1: %d", ft_str_is_printable(str2));
	return (0);
}*/

/* ex07 */
int is_lowercase(char letter)
{
	int result;

	result = 0;
	if (letter >= 'a' && letter <= 'z')
		result = 1;
	return (result);
}

char *ft_strupcase(char *str)
{
	int counter;
	counter = 0;
	while (str[counter] != '\0')
	{
		if (is_lowercase(str[counter]) == 1)
		{
			str[counter] -= 32;
		}
		counter++;
	}

	return (str);
}

/*int main(void)
{
	char str[] = "hola, ¿que tal?";
	
	printf("Minusculas: %s \n", str);
	ft_strupcase(str);
	printf("Resultado: %s", ft_strupcase(str));
	return (0);
}*/

/* ex08 */
int is_uppercase(char letter)
{
	int result;

	result = 0;
	if (letter >= 'A' && letter <= 'Z')
		result = 1;
	return (result);
}

char *ft_strlowcase(char *str)
{
	int counter;
	
	counter = 0;
	while (str[counter] != '\0')
	{
		if (is_uppercase(str[counter]) == 1)
		{
			str[counter] += 32;
		}
		counter++;
	}

	return (str);
}

/*int main(void)
{
	char str[] = "HoLa, ¿qUe TaL?";
	
	printf("Cadena de texto: %s \n", str);
	ft_strupcase(str);
	printf("Resultado: %s", ft_strlowcase(str));
	return (0);
}*/

/* ex09 */
int is_number(char letter)
{
	int result;

	result = 0;
	if (letter >= '0' && letter <= '9')
		result = 1;
	return (result);
}
 
int		is_space(char letter)
{
	int result;

	result = 0;
	if (is_lowercase(letter) == 0 && is_uppercase(letter) == 0 && is_number(letter) == 0)
		result = 1;
	return (result);
}

char	*ft_strcapitalize(char *str)
{
	int counter;
	int space;
	
	counter = 0;
	space = 1;
	while (str[counter] != '\0')
	{
		if (is_space(str[counter]) == 1)
		{
			space = 1;
			counter++;
			continue;
		}
		if (is_uppercase(str[counter]) == 1)
		{
			str[counter] += 32;
		}
		if (space == 1)
		{
			if (is_lowercase(str[counter]) == 1)
			{
				str[counter] -= 32;
			}
		}
		counter++;
		space = 0;
	}
	return (str);
}

/*int main(void)
{
	char str[] = "hoLa, como estas? 42palaBras cuarenta-y-dos; cincuenta+y+uno";
	printf("Cadena de texto: %s \n", str);
	printf("Resultado: %s", ft_strcapitalize(str));
	return (0);
}*/

/* ex10 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				c;

	i = 0;
	c = 0;
	while (src[i] != '\0')
	{
		c++;
		i++;
	}
	i = 0;
	while (i < size - 1 && size > 0)
	{
		if (src[i] == '\0')
		{
			dest[i] = src[i];
			return (c);
		}
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (c);
}

/*int main(void)
{
	char src[] = "hola que tal";
	char des[] = "adios       ";

	printf("Antes: %s \n", des);
	strlcpy(des, src, sizeof(des));
	printf("Despues: %s \n", des);
	//printf("La funcion real: %lu \n", strlcpy(des, src, sizeof(des)));
	printf("Mi funcion: %u", ft_strlcpy(des, src, 10));
	return (0);
}*/

/* ex11 */
void	ft_putchar(char put)
{
	write(1, &put, 1);
}

void	ft_hex_converter(char *hex, unsigned char c)
{
	hex[0] = 92;
	if (c / 16 <= 9)
		hex[1] = c / 16 + 48;
	else
		hex[1] = c / 16 + 87;
	if (c % 16 <= 9)
		hex[2] = c % 16 + 48;
	else
		hex[2] = c % 16 + 87;
	hex[3] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		j;
	char	hex[4];
	char	*ptr;

	i = 0;
	j = 0;
	hex[0] = '\0';
	ptr = &hex[0];
	while (str[i] != '\0')
	{
		if (str[i] > 126 || str[i] < 32)
		{
			ft_hex_converter(ptr, (unsigned char)str[i]);
			while (j < 3)
			{
				ft_putchar(hex[j]);
				j++;
			}
			j = 0;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

/*int main(void)
{
	char src[] = "h\eol\ra. \nque\t t\aal estas?";

	ft_putstr_non_printable(src);
	return (0);
}*/

/* ex12 */
void	print_memory_hexa(unsigned long int number)
{
	char *trans;
	char hexa[15];
	int i;

	i = 14;
	trans = "0123456789abcdef";
	while (number > 0)
	{
		hexa[i] = trans[number % 16];
		
		number /= 16;
		i--;
	}
	i = 0;
	while(i < 15)
	{
		if(hexa[i] >= '0' && hexa[i] <= 'f')
			write(1, &hexa[i], 1);
		else
			ft_putchar('0');		
		i++;
	}
	write(1, ": ", 2);
}

void	decimal_to_hexa2(char transf, int j)
{
	char	*hexa;
	char	to[2];
	int		i;
	int		k;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < 2)
	{
		to[i] = hexa[transf % 16];
		transf /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(to[i]);
		i--;
	}
	if (j % 2)
		write(1, " ", 1);
}

void	print_special_chars(char *ptr, unsigned int size, unsigned int i)
{
	int	j;
	char c;

	j = 0;
	while (j < 16)
	{
		c = ptr[j];
		if (c >= ' ' && c <= '~')
			write(1, &ptr[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
	if (i < (size - 17))
		write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned	int			j;
	int						i;
	unsigned	long	int mem;
	char					*ptr;

	ptr = addr;
	j = 0;
	i = 0;
	mem = (unsigned long int)addr;
	while (i < size - 1)
	{
		print_memory_hexa(mem);
		while (j < 16)
		{
			decimal_to_hexa2(ptr[j], j);
			j++;
		}
		j = 0;
		print_special_chars(ptr, size, i);
		ptr += 16;
		mem += 16;
		i += 16;
	}
	return (addr);
}


/*int main(void)
{
	char src[] = "Bonjour les aminches\t\n\tc est  fou\ttout\tce qu on peut faire avec\t\n\nprint_memory\n\n\n\tlol.lol\n asdqh";
	ft_print_memory(src, sizeof(src));
	return (0);
}*/
