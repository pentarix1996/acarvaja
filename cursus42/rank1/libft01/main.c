/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:25:18 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/15 15:25:31 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libft.h>
#include "libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void *		lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	/*ft_memset*/
	/* ************************************************* */
	/*char str1[50] = "Funcion Real con memset"; 
	char str2[50] = "Funcion Real con memset";
    printf("\nBefore memset(): %s\n", str1);
	printf("\nBefore memset(): %s\n", str2);
  
    memset(str1 + 13, '.', 8*sizeof(char));
	ft_memset(str2 + 13, '.', 8*sizeof(char));  
  
    printf("\nAfter memset():  %s", str1);
	printf("\nAfter ft_memset():  %s", str2); */
	/* ************************************************* */

	/*ft_bzero*/
	/* ************************************************* */
	/*char str1[20] = "Ejemplo de bzero";
	char str2[20] = "Ejemplo de bzero";
	int i = 2;

	printf("Real Antes: %s", str1);
	printf("\nMia Antes: %s", str2);
	bzero(str1 + 2, 5);
	ft_bzero(str2 + 2, 5);
	printf("\nReal Despues: %s", str1);
	while (str1[i] == '\0')
		printf("[%d], ", i++);
	printf("\nMia Despues: %s", str2);
	i = 2;
	while (str2[i] == '\0')
		printf("[%d], ", i++);*/
	/* ************************************************* */

	/*ft_memcpy*/
	/* ************************************************* */
	/*char src[50] = "Ejemplo de memcpy";
	char dest1[50];
	char dest2[50];

	strcpy(dest1, "Hello world");
	printf("Real Before memcpy dest = %s\n", dest1);
	memcpy(dest1, src, strlen(src)+1);
	printf("Real After memcpy dest = %s\n", dest1);
	printf("*************************************************");
	strcpy(dest2, "Hello world");
	printf("\nMia Before memcpy dest = %s\n", dest2);
	ft_memcpy(dest2, src, strlen(src)+1);
	printf("Mia After memcpy dest = %s\n", dest2);*/
	/* ************************************************* */
	
	/*ft_memccpy*/
	/* ************************************************* */
	/*char src[50] = "Ejemplo de: memccpy";
	char dest1[50];
	char dest2[50];

    memset( dest1, '\0', 50);
    printf("Valor de retorno: %p\nReal Despues de memccpy: %s\n", memccpy(dest1, src, ':', 50), dest1);
	printf("*************************************************");
    memset( dest2, '\0', 50);
    printf("\nValor de retorno: %p\nMia Despues de memccpy: %s\n", ft_memccpy( dest2, src, ':', 50), dest2);*/
	/* ************************************************* */

	/*ft_memmove*/
	/* ************************************************* */
	/*char dest1[] = "oldstring";
	char dest2[] = "oldstring";
	const char src[]  = "newstring";

	printf("Puntero: %p\nBefore memmove dest = %s, src = %s\n", &dest1, dest1, src);
	printf("Puntero: %p\nAfter memmove dest = %s, src = %s\n", memmove(dest1, src, 9), dest1, src);
	printf("*************************************************");
	printf("\nPuntero: %p\nBefore memmove dest = %s, src = %s\n", &dest2, dest2, src);
	printf("Puntero: %p\nAfter memmove dest = %s, src = %s", ft_memmove(dest2, src, 9), dest2, src);*/
	/* ************************************************* */

	/*ft_memchr*/
	/* ************************************************* */
	/*const char str[] = "Hello World. My name is Antonio.";
	const char ch = '.';
	char *ret;

	ret = memchr(str, ch, strlen(str));
	printf("str: %p\nret: %p\nReal Function: String after |%c| is - |%s|\n", str, ret, ch, ret);
	ret = ft_memchr(str, ch, strlen(str));
	printf("str: %p\nret: %p\nMy Function: String after |%c| is - |%s|\n", str, ret, ch, ret);*/
	/*char *pouet = "z";
	char *lolzer = (char *)&pouet[2];
	const char *str;
	
	lolzer = "aaaaaaaaaa";
	str = ft_memchr(pouet, 'a', 50);
	if (!str)
		printf("NULL");
	else
	{
		printf("%s", str);
	}*/
	/* ************************************************* */

	/*ft_memcmp*/
	/* ************************************************* */
	/*char str1[15];
	char str2[15];
	int ret;
	int ret2;

	memcpy(str1, "ab\0\0\0cdef", 9);
	memcpy(str2, "ab\0\0\0ddef", 9);

	ret = memcmp(str1, str2, 9);
	ret2 = ft_memcmp(str1, str2, 9);

	printf("---------Real Function----------\n");
	if(ret > 0)
		printf("str2 is less than str1 (%d)", ret);
	else if(ret < 0)
		printf("str1 is less than str2 (%d)", ret);
	else
		printf("str1 is equal to str2(%d)", ret);
	printf("\n---------My Function----------\n");
	if(ret2 > 0)
		printf("str2 is less than str1 (%d)", ret2);
	else if(ret2 < 0)
		printf("str1 is less than str2 (%d)", ret2);
	else
		printf("str1 is equal to str2(%d)", ret2);*/
	/* ************************************************* */

	/*ft_strlen*/
	/* ************************************************* */
	/*char *str = "Hello World";
	printf("Real function: %lu\n", strlen(str));
	printf("My function: %zu", ft_strlen(str));*/
	/* ************************************************* */

	/*ft_isalpha*/
	/* ************************************************* */
	/*char test_true = 'h';
	char test_false = ',';
	printf("---Real Function---\nTrue test: %d\nFalse test: %d", isalpha(test_true), isalpha(test_false));
	printf("\n---My Function---\nTrue test: %d\nFalse test: %d", ft_isalpha(test_true), ft_isalpha(test_false));*/
	/* ************************************************* */

	/*ft_isdigit*/
	/* ************************************************* */
	/*char test_true = '9';
	char test_false = 'a';
	printf("---Real Function---\nTrue test: %d\nFalse test: %d", isdigit(test_true), isdigit(test_false));
	printf("\n---My Function---\nTrue test: %d\nFalse test: %d", ft_isdigit(test_true), ft_isdigit(test_false));*/
	/* ************************************************* */

	/*ft_isalnum*/
	/* ************************************************* */
	/*char test_true1 = 'Z';
	char test_true2 = '0';
	char test_false = ',';
	printf("---Real Function---\nTrue test: (1)%d, (2)%d\nFalse test: %d", isalnum(test_true1), isalnum(test_true2), isdigit(test_false));
	printf("\n---My Function---\nTrue test: (1)%d, (2)%d\nFalse test: %d", ft_isalnum(test_true1), ft_isalnum(test_true2), ft_isalnum(test_false));*/
	/* ************************************************* */

	/*ft_isascii*/
	/* ************************************************* */
	/*printf("---Real Function---\nTrue test: (1)%d, (2)%d\nFalse test: %d", isascii(0), isascii(127), isascii(128));
	printf("\n---My Function---\nTrue test: (1)%d, (2)%d\nFalse test: %d", ft_isascii(0), ft_isascii(127), ft_isascii(128));*/
	/* ************************************************* */

	/*ft_isprint*/
	/* ************************************************* */
	/*printf("---Real Function---\nTrue test: (1)%d, (2)%d\nFalse test: %d", isprint(32), isprint(126), isprint(31));
	printf("\n---My Function---\nTrue test: (1)%d, (2)%d\nFalse test: %d", ft_isprint(32), ft_isprint(126), ft_isprint(31));*/
	/* ************************************************* */

	/*ft_toupper*/
	/* ************************************************* */
	/*printf("---Real Function---\nChange test: (1)%c, (2)%c\nNo change test: %c", toupper(97), toupper(122), toupper(96));
	printf("\n---My Function---\nChange test: (1)%c, (2)%c\nNo change: %c", ft_toupper(97), ft_toupper(122), ft_toupper(96));*/
	/* ************************************************* */

	/*ft_tolower*/
	/* ************************************************* */
	/*printf("---Real Function---\nChange test: (1)%c, (2)%c\nNo change test: %c", tolower('A'), tolower('Z'), tolower('{'));
	printf("\n---My Function---\nChange test: (1)%c, (2)%c\nNo change: %c", ft_tolower('A'), ft_tolower('Z'), ft_tolower('{'));*/
	/* ************************************************* */

	/*ft_strchr*/
	/* ************************************************* */
	/*const char str[] = "Hello Word. Hello Antonio";
	const char ch = '.';
	char *ret;

	ret = strchr(str, ch);
	printf("Real function: String after |%c| is - |%s|\n", ch, ret);
	ret = ft_strchr(str, ch);
	printf("My function: String after |%c| is - |%s|\n", ch, ret);*/
	/* ************************************************* */

	/*ft_strrchr*/
	/* ************************************************* */
	/*const char str[] = "Hello Word Hello Antonio";
	const char ch = '.';
	char *ret;

	ret = strrchr(str, ch);
	printf("Real function: String after |%c| is - |%s|\n", ch, ret);
	ret = ft_strrchr(str, ch);
	printf("My function: String after |%c| is - |%s|\n", ch, ret);*/
	/* ************************************************* */

	/*ft_strncmp*/
	/* ************************************************* */
	/*char str1[15];
	char str2[15];
	int ret;
	int ret2;

	strcpy(str1, "abddefA");
	strcpy(str2, "abddef");

	ret = strncmp(str1, str2, 7);
	ret2 = ft_strncmp(str1, str2, 7);

	printf("---------Real Function----------\n");
	if(ret > 0)
		printf("str2 is less than str1 (%d)", ret);
	else if(ret < 0)
		printf("str1 is less than str2 (%d)", ret);
	else
		printf("str1 is equal to str2(%d)", ret);
	printf("\n---------My Function----------\n");
	if(ret2 > 0)
		printf("str2 is less than str1 (%d)", ret2);
	else if(ret2 < 0)
		printf("str1 is less than str2 (%d)", ret2);
	else
		printf("str1 is equal to str2(%d)", ret2);*/
	/* ************************************************* */

	/*ft_strlcpy*/
	/* ************************************************* */
	/*char src[] = "hola que tal";
	char des[] = "adios";
	char des2[] = "adios";
	size_t result;

	printf("Antes: %s \n", des);
	result = strlcpy(des, src, strlen(des));
	printf("---Original---\nDespues: %s| Return: %zu\n", des, result);
	result = ft_strlcpy(des2, src, strlen(des2));
	printf("\n---Mi funcion---\nDespues: %s| Return: %zu", des2, result);*/
	
	/*char	dest[15];

	memset(dest, 'r', 15);
	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, dest, 15);*/
	/* ************************************************* */

	/*ft_strlcat*/
	/* ************************************************* */
	/*char src[50], dest1[50], dest2[50];

	strcpy(src,  "This is source");
	strcpy(dest1, "This is destination");
	strcpy(dest2, "This is destination");

	
	printf("---Real Function---\nReturn: |%lu|Final destination string : |%s|", strlcat(dest1, src, 5), dest1);
	printf("\n---My Function---\nReturn: |%lu|Final destination string : |%s|", ft_strlcat(dest2, src, 5), dest2);*/

	/*char *dest;
	
	dest = malloc(sizeof(dest) * 15);
	memset(dest, 'r', 15);
	printf("Resultado: %zu\n%s", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5), dest);*/
	/* ************************************************* */

	/*ft_strnstr*/
	/* ************************************************* */
	/*char str1[50] = "estoy bien cl?aro que si";
	char str3[50] = "estoy bien cl?aro que si";
	char str2[50] = "o";
	printf("Resultado previsto: %s", strnstr(str1, str2, 24));
	printf("\nMi resultado: %s", ft_strnstr(str3, str2, 24));
	return (0);*/
	/* ************************************************* */

	/*ft_atoi*/
	/* ************************************************* */
	/*char *str = "   \n\n\v\f\t\r\t -+54";
	printf("---Real Function---\nResult: %d", atoi(str));
	printf("\n---My Function---\nResult: %d", ft_atoi(str));*/
	/* ************************************************* */

	/*ft_calloc*/
	/* ************************************************* */
	/*int i, n;
	int *a;

	printf("Number of elements to be entered:");
	scanf("%d",&n);
	a = (int*)ft_calloc(n, sizeof(int));
	printf("Enter %d numbers:\n",n);
	for(i=0 ; i < n ; i++)
		scanf("%d",&a[i]);
	printf("---The numbers entered are---");
	for(i=0 ; i < n ; i++) 
		printf("\n%d --> [%d]%p", a[i], i, &a[i]);
	free(a);*/
	/* ************************************************* */

	/*ft_strdup*/
	/* ************************************************* */
	/*char *p1 = "Hello World";
    char *p2;
	printf("---PreCommand---\nOriginal String: %s --> ptr: %p\nDuplicated string: %s --> ptr: %p", p1, &p1, p2, &p2);
    p2 = ft_strdup(p1);
    printf("\n---PostCommand---\nOriginal String: %s --> ptr: %p\nDuplicated string: %s --> ptr: %p", p1, &p1, p2, &p2);
	free (p2);*/
	/* ************************************************* */

	/*ft_strjoin*/
	/* ************************************************* */
    /*char *ptr1 = "Hello";
	char *ptr2 = " World";
	printf("%s", ft_strjoin(ptr1, ptr2));*/
	/* ************************************************* */

	/*ft_strtrim*/
	/* ************************************************* */
	/*char *str = "abc hola cba";
	char *set = "bca ";

	printf("Result: %s", ft_strtrim(str, set));*/

	/*char *s1 = "    \t  \n\n\n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");

	printf("%s", ret);
	if (!strcmp(ret, s2))
		printf("Good");
	else
		printf("Mal");*/
	/* ************************************************* */

	/*ft_split*/
	/* ************************************************* */
	/*char *ptr = "Hola Que    Tal";
	char **result;
	int i;

	result = ft_split(ptr, ' ');
	i = 0;
	while (result[i] != '\0')
	{
		printf("%s\n", result[i]);
		i++;
	}*/
	/* ************************************************* */

	/*ft_itoa*/
	/* ************************************************* */
	//ft_print_result(ft_itoa(0));

	/*char *i1 = ft_itoa(-1234);
	printf("[%s]\n", i1);
	if (!strcmp(i1, "-1234"))
		printf("Good");
	else
		printf("False");*/
	/* ************************************************* */

	/*ft_lstnew.c*/
	/* ************************************************* */
	/*char *str = "Hellow world";
	t_list *element = NULL;

	element = ft_lstnew(str);
	printf("%s", element->content);
	free(element);*/
	/* ************************************************* */

	/*ft_lstadd_front*/
	/* ************************************************* */
	/*t_list *l = ((void *)0);
	t_list *n = ft_lstnew(ft_strdup("OK"));

	ft_lstadd_front(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
	{
		free(l->next);
		free(l);
		printf("Todo ok\n");
	}*/
	/* ************************************************* */

	/*ft_lstadd_front*/
	/* ************************************************* */
	/*t_list *l;
	int actual;
	int expected;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = 3;
	actual = ft_lstsize(l);
	if (actual == expected)
		printf("Good\n");
	else
		printf("Mal");*/
	/* ************************************************* */

	/*ft_lstmap*/
	/* ************************************************* */
	/*t_list *l = ft_lstnew(ft_strdup(" 1 2 3 "));
	t_list *ret;
	
	l->next = ft_lstnew(ft_strdup("ss"));
	l->next->next = ft_lstnew(ft_strdup("-_-"));
	ret = ft_lstmap(l, lstmap_f, ((void *)0));
	printf("%p\n", ret);
	printf("Test: %s\n", ret->next->content);
	if (!strcmp(ret->content, "OK !") && !strcmp(ret->next->content, "OK !") && !strcmp(ret->next->next->content, "OK !") && !strcmp(l->content, " 1 2 3 ") && !strcmp(l->next->content, "ss") && !strcmp(l->next->next->content, "-_-"))
		printf("Bien");
	else
		printf("Mal");*/
	/* ************************************************* */
	return (0); 
}