/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:01:25 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 13:22:59 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* ex00 */
char *ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(src));
	if (ptr == NULL)
		return (ptr);
	i = -1;
	while (src[++i] != '\0')
		ptr[i] = src[i];
	ptr[i] = '\0';
	return (ptr);
}

/*int main(int argc, char **argv)
{
	char *str = "Hola";
	char *teststr = "Hola Mundo";
	char *mystr = "Hola";
	char *mytest = "Hola Mundo";

	printf("Funcion real:\nSTR: %p\n", str);
	str = strdup(teststr);
	printf("STR: %p --> %s\n", str, str);
	printf("Test: %p\n\n", teststr);
	printf("My funcion\nMYSTR: %p\n", mystr);
	mystr = ft_strdup(mytest);
	printf("MYSTR: %p --> %s\n", mystr, mystr);
	printf("MyTest: %p", mytest);
	free(str);
	free(mystr);
	return (0);
}*/

/* ex01 */
int *ft_range(int min, int max)
{
	int *ptr;
	unsigned int i;
	unsigned int range;

	range = max - min;
	ptr = 0;
	if (min >= max)
		return (ptr);
	ptr = malloc(sizeof(int) * range);
	if (!ptr)
		return (ptr);
	i = 0;
	while (i < range)
		ptr[i++] = min++;
	return (ptr);
}

/*int main(int argc, char **argv)
{
	unsigned int min = -3715;
	unsigned int max = 2147483647;
	int *ptr;
	unsigned int i;
	(void) argc;
	(void) argv;
	
	i = 0;
	ptr = ft_range(min, max);
	if (!ptr)
		printf("Rango incorrecto");
	else
	{
		printf("Rango: %d ~ %d, result: ", min, max-1);
		while(i < (max - min))
		{
			printf("%d, ", ptr[i]);
			i++;
		}
	}
	return (0);
}*/

/* ex02 */
/*int ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	unsigned int	tam;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tam = max - min;
	*range = malloc(sizeof(int) * (max - min));
	if (!range)
		return (0);
	i = 0;
	while (i < tam)
	{
		range[0][i] = min + i;
		i++;
	}
	return (i);
}*/

int		ft_ultimate_range(int **range, int min, int max)
{
	int	bound;
	int	index;
	int	*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	bound = max - min - 1;
	if ((buffer = malloc(bound * sizeof(int))) == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	index = 0;
	while (index <= bound)
	{
		buffer[index] = min + index;
		index++;
	}
	return (bound + 1);
}

/*int main(void)
{
	int	**ptr1;
	int	min;
	int	max;
	int i;
	unsigned int	size;

	min = -451;
	max = 214;
	size = ft_ultimate_range(ptr1, min, max);
	printf("Tamaño total: %u\n", size);
	i = 0;
	while(i < (max - min))
	{
		printf("%d-", ptr1[0][i]);
		i++;
	}
}*/

/* ex03 */
/*char *ft_strjoin(int size, char **strs, char *sep)
{
	char *str;
	int i;
	int j;
	int k;

	str = 0;
	if (size <= 0)
		return (str);
	str = malloc(sizeof(char) * size);
	i = -1;
	j = -1;
	k = -1;
	while (++i < size)
	{
		while (strs[i][++j] != '\0')
			str[++k] = strs[i][j];
		j = -1;
		if (i < size-1)
			while (sep[++j] != '\0')
				str[++k] = sep[j];
		j = -1;
	}
	str[k] = '\0';
	return (str);
}*/


char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while ((dest[i] = src[j]) != '\0')
	{
		i++;
		j++;
	}
	return (dest);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = size;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	while (j > 0)
		i += ft_strlen(strs[--j]);
	if ((p = (char *)malloc(i * sizeof(*p))) != NULL && size > 0)
	{
		*p = '\0';
		while (j < size - 1)
		{
			p = ft_strcat(p, strs[j++]);
			p = ft_strcat(p, sep);
		}
		p = ft_strcat(p, strs[j]);
	}
	return (p);
}

int main(int argc, char **argv)
{
	char *strfull;
	char **strs;
	int i;

	(void) argc;
	(void) argv;
	strs = malloc(sizeof(char *) * 4);
	i = 0;
	while (i <= 4){
		strs[i] = malloc(sizeof(char) * 11);
		i++;
	}
	strs[0] = "hola";
	strs[1] = "mundo";
	strs[2] = "que";
	strs[3] = "tal?";
	strfull = ft_strjoin(4, strs, " - ");
	printf("%s", strfull);
	free(strfull);
}
/* ex04 */

/* Archivo 2 */
int		is_correct_base(char *base)
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

int		ft_isspace(char space)
{
	int		result;
	char	*pos_spaces;

	result = 0;
	pos_spaces = " \f\n\r\t\v";
	if (space == *pos_spaces)
		result = 1;
	while (*pos_spaces != '\0' && space != *pos_spaces++)
	{
		if (space == *pos_spaces)
		{
			result = 1;
			break ;
		}
	}
	return (result);
}

int		nmb_on_base(char letter, char *base)
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

int		calc_basenbr(char *base, char nbrb, int pos)
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

int		ft_atoi_base(char *str, char *base)
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

/* Archivo 1 */
char	insert_new_char(int nbr, char *base)
{
	char res;
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	res = base[nbr % i];
	return (res);
}

void	ft_swap(char *a, char *b)
{
	char swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

char	*revert(char *ptr)
{
	int j;
	int i;
	int k;

	i = 0;
	j = 0;
	while (ptr[j] != '\0')
		j++;
	k = j;
	j -= 1;
	if(ptr[0] == '-')
	{
		while (++i < k/2 + 1)
			ft_swap(&ptr[i], &ptr[j--]);
	}
	else
	{
		while (i < k/2)
			ft_swap(&ptr[i++], &ptr[j--]);
	}
	return(ptr);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int				i;
	char			*new_nbr;
	int				j;

	new_nbr = malloc(sizeof(char) * 200);
	if (is_correct_base(base) != 0)
	{
		i = 0;
		j = 0;
		while (base[j] != '\0')
			j++;
		j--;
		while (nbr != 0)
		{
			if (nbr < 0)
			{
				new_nbr[0] = '-';
				nbr = nbr * -1;
				i++;
			}
			new_nbr[i++] = insert_new_char(nbr, base);
			nbr /= j;
		}
	}
	return (revert(new_nbr));
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int realnbr;
	char *new_nbr;

	if (is_correct_base(base_from) == 0 || is_correct_base(base_to) == 0)
		new_nbr = NULL;
	else
	{	
		realnbr = ft_atoi_base(nbr, base_from);
		new_nbr = ft_putnbr_base(realnbr, base_to);
	}
	return (new_nbr);
}

/*int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char *nbr = "   \t+-+-111dgfgds4";
	char *base_from = "01";
	char *base_to = "0123456";
	char *result = "HOLASDFAS";

	result = ft_convert_base(nbr, base_from, base_to);
	printf("Pasamos de: %s en base: %s  --> a: %s en base: %s", nbr, base_from, result, base_to);
}*/

/* ex05 */
/* Sol1 --> KO */
/*int		compare(char *dest, char *src)
{
	while (*dest && *src)
	{
		if (*dest != *src)
			return (0);
		dest++;
		src++;
	}
	return (*src == '\0');
}

int		ft_strstr_tunned(char *str, char *to_find)
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

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		calc_range(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 1;
	j = 0;
	ptr = str;
	while (charset[j] != '\0')
		j++;
	while (ft_strstr_tunned(ptr, charset) != 0)
	{
		ptr = ft_strstr(ptr, charset);
		k = j;
		while (k-- > 0)
			ptr++;
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**table;
	int		mem_range;

	mem_range = calc_range(str, charset);
	table = malloc(sizeof(char *) * mem_range);
	if (table == NULL)
		return (table);
	j = 0;
	while (charset[j] != '\0')
		j++;
	i = 0;
	while (ft_strstr_tunned(str, charset) != 0)
	{
		table[i] = malloc(sizeof(char) * 200);
		mem_range = ft_strstr_tunned(str, charset);
		table[i] = ft_strncpy(table[i], str, mem_range);
		str = ft_strstr(str, charset);
		mem_range = j;
		while (mem_range-- > 0)
			str++;
		i++;
	}
	if (i == 0)
	{
		table[i] = malloc(sizeof(char) * 200);
		table[i++] = str;
	}
	else
		table[i] = str;
	table[i + 1] = NULL;
	return (table);
}*/
/* Sol2 */
int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_word(char c, char before, char *charset)
{
	return (!is_separator(c, charset) && is_separator(before, charset));
}

int		words_count(char *str, char *charset)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_word(str[i], str[i - 1], charset) ||
			(!is_separator(str[i], charset) && i == 0))
			count++;
		i++;
	}
	return (count);
}

int		*obtain_size(char *str, char *charset)
{
	int		indx;
	int		i;
	int		count;
	int		*size;

	i = 0;
	count = words_count(str, charset);
	size = malloc(count * sizeof(int));
	while (i <= count)
	{
		size[i] = 0;
		i++;
	}
	i = 0;
	indx = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset))
			size[indx]++;
		else if (i > 0 && !is_separator(str[i - 1], charset))
			indx++;
		i++;
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		j;
	int		indx;
	int		*size;

	words = malloc((words_count(str, charset) + 1) * sizeof(char*));
	size = obtain_size(str, charset);
	indx = 0;
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (!is_separator(str[i], charset))
		{
			if (i == 0 || is_word(str[i], str[i - 1], charset))
				words[indx] = malloc(size[indx] * sizeof(char));
			words[indx][j] = str[i];
			words[indx][++j] = '\0';
		}
		else if (i > 0 && !is_separator(str[i - 1], charset) && ++indx)
			j = 0;
	}
	words[words_count(str, charset)] = 0;
	return (words);
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char **table;
	int i;
	char *str = "Hola - que - tal - estas?";
	char *charset = " - ";

	i = -1;
	table = ft_split(str, charset);
	while (table[++i] != '\0')
		printf("%s\n", table[i]);
	return (0);
}