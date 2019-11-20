/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:23:05 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/12 22:02:35 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* ex00 */
unsigned int	ft_strlen(char *str)
{
	unsigned int tam;

	tam = 0;
	while (str[tam] != '\0')
	{
		tam++;
	}
	return (tam);
}

int ft_strcmp(char *s1, char *s2)
{
	int result;
	int	cmp1;
	int i;
	
	i = 0;
	cmp1 = 0;
	result = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if(i < ft_strlen(s1))
			result += (unsigned char)s1[i];
		if(i < ft_strlen(s2))
			cmp1 += (unsigned char)s2[i];
		if ((result - cmp1) < 0)
			break ;
		else if ((result - cmp1) > 0)
			break ;
		i++;
	}
	result -= cmp1;
	return (result);
}

/*int main(void)
{
	char *str1 = "d?k";
	char *str3 = "d¿a";

	printf("Resultado previsto: %d", strcmp(str1, str3));
	printf("\nMi resultado: %d", ft_strcmp(str1, str3));
	return (0);
}*/

/* ex01 */
int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int 			result;
	int				cmp1;
	unsigned int	i;

	i = 0;
	cmp1 = 0;
	result = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (i < ft_strlen(s1))
			result += (unsigned char)s1[i];
		if (i < ft_strlen(s2))
			cmp1 += (unsigned char)s2[i];
		if ((result - cmp1) < 0)
			break ;
		else if ((result - cmp1) > 0)
			break ;
		i++;
	}
	result -= cmp1;
	return (result);
}

/*int main(void)
{
	char *str1 = "ñ5¿";
	char *str3 = "354";

	printf("Resultado previsto: %d", strncmp(str1, str3, 2));
	printf("\nMi resultado: %d", ft_strncmp(str1, str3, 2));
	return (0);
}*/

/* ex02 */
char	*ft_strcat(char *dest, char *src)
{
	char *ptr;
	
	ptr = dest + ft_strlen(dest);
	while (*src != '\0')
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

/*int main(void)
{
	char str1[5] = "que ";
	char str3[5] = "que ";
	char str2[20] = "Hola";

	//printf("Resultado previsto: %s", strcat(str1, str2));
	printf("\nMi resultado: %s", ft_strcat(str3, str2));
	return (0);
}*/

/* ex03 */
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *ptr;

	ptr = dest + ft_strlen(dest);
	while (*src != '\0' && nb--)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

/*int main(void)
{
	char str1[50] = "Hola";
	char str3[50] = "Hola";
	char str2[50] = " adios";

	printf("Resultado previsto: %s", strncat(str1, str2, 10));
	printf("\nMi resultado: %s", ft_strncat(str3, str2, 10));
	return (0);
}*/

/* ex04 */
int		compare(char *dest, char *src)
{
	while (*dest && *src)
	{
		if (*dest != *src)
			return 0;
		dest++;
		src++;
	}
	return (*src == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if(*to_find == '\0')
		return str;
	while(*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return  str;
		str++;
	}
	return (0);
}

/*int main(void)
{
	char str1[50] = "estoy bien cl?aro que si";
	char str3[50] = "estoy bien cl?aro que si";
	char str2[50] = "sii";
	printf("Resultado previsto: %s", strstr(str1, str2));
	printf("\nMi resultado: %s", ft_strstr(str3, str2));
	return (0);
}*/

/* ex05 */
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = ft_strlen(src);
	while (*dest && size > 0 && size--)
	{
		dest++;
		i++;
	}
	while (*src && size > 1 && size--)
		*dest++ = *src++;
	if (size == 1)
		*dest = '\0';
	return (j + i);
}

int main(void)
{
	char str1[50] = "42dfgdl33rbSxpMPzNH";
	char str3[50] = "42dfgdl33rbSxpMPzNH";
	char str2[50] = "fds";

	printf("Resultado previsto: %lu", strlcat(str1, str2, 10));
	printf("\nRes: %s", str1);
	printf("\nMi resultado: %u", ft_strlcat(str3, str2, 10));
	printf("\nMi res: %s", str3);
	return (0);
}
