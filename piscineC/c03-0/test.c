/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:23:05 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/11 18:57:04 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* ex00 */
int ft_strcmp(char *s1, char *s2)
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
			break;
		else if ((result - cmp1) > 0)
			break;
		i++;
	}

	if (s1[i] != '\0' && (result - cmp1) == 0)
		result+= s1[i];
	result -= cmp1;
	return (result);
}

int main(void)
{
	char *str1 = "25432";
	char *str3 = "25432v";

	printf("Resultado previsto: %d", strcmp(str1, str3));
	printf("\nMi resultado: %d", ft_strcmp(str1, str3));
	return (0);
}

/* ex01 */
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int 			result;
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

/*int main(void)
{
	char *str1 = "254325a";
	char *str2 = "13";
	char *str3 = "254325";

	printf("Resultado previsto: %d", strncmp(str1, str3, 3));
	printf("\nMi resultado: %d", ft_strncmp(str1, str3, 3));
	return (0);
}*/

/* ex02 */
char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
	char str1[50] = "Hola";
	char str3[50] = "Hola";
	char str2[50] = " Mundo";

	printf("Resultado previsto: %s", strcat(str1, str2));
	printf("\nMi resultado: %s", ft_strcat(str3, str2));
	return (0);
}*/

/* ex03 */
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	int j;

	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0' && i < nb)
	{
		dest[j + i] = src[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
	char str1[50] = "Hola";
	char str3[50] = "Hola";
	char str2[50] = " Mundo";

	printf("Resultado previsto: %s", strncat(str1, str2, 12));
	printf("\nMi resultado: %s", ft_strncat(str3, str2, 12));
	return (0);
}*/

/* ex04 */
char *ft_strstr(char *str, char *to_find)
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

/*int main(void)
{
	char str1[50] = "estoy bien claro que si";
	char str3[50] = "estoy bien claro que si";
	char str2[50] = "";
	printf("Resultado previsto: %s", strstr(str1, str2));
	printf("\nMi resultado: %s", ft_strstr(str3, str2));
	return (0);
}*/

/* ex05 */
unsigned int	length_str(char *src)
{
	unsigned int i;

	i = 0;
	while(src[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;
	unsigned int comp;

	if (length_str(dest) <= size)
		result = length_str(dest) + length_str(src);
	else
		result = length_str(src) + length_str(dest) - (length_str(dest) - size);
	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	if (size == 0)
		comp = size;
	else
		comp = size - 1;
	
	while (src[i] != '\0' && (j + i) < comp)
	{
		dest[j + i] = src[i];
		i++;
	}
	return (result);
}

/*int main(void)
{
	char str1[50] = "Hola";
	char str3[50] = "Hola";
	char str2[50] = " Mundo";

	printf("Resultado previsto: %lu", strlcat(str1, str2, 0));
	printf("\nRes: %s", str1);
	printf("\nMi resultado: %u", ft_strlcat(str3, str2, 0));
	printf("\nMi res: %s", str3);
	return (0);
}*/
