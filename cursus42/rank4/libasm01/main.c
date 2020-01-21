/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:30:18 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/21 12:40:44 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libasm.h"

void test_strlen(int res_or, int res_m)
{
    printf("%d\t\t|\t%d\t", res_or,  res_m);
    if (res_or == res_m)
        printf("✅");
    else
        printf("❌");
    printf("\n");
}

void test_strcpy(char *res_or, char *res_m)
{
    printf("%s\t\t|\t%s\t", res_or,  res_m);
    if (res_or == res_m)
        printf("✅");
    else
        printf("❌");
    printf("\n");
}

void test_strcmp(int res_or, int res_m)
{
    printf("%d\t\t|\t%d\t", res_or,  res_m);
    if (res_or == res_m)
        printf("✅");
    else
        printf("❌");
    printf("\n");
}

void test_strdup(char *res_or, char *res_m)
{
    printf("%s\t\t|\t%s\t", res_or,  res_m);
    if (ft_strcmp(res_or, res_m) == 0 && res_or != res_m)
        printf("✅");
    else
        printf("❌");
    printf("\n");
}

int main(void)
{
    char *str;

    // Algunas funciones hacen llamadas al SystemCall http://syscalls.kernelgrok.com/ //
    // --- STRLEN --- //
    str = strdup("Hola mundo");
    printf("---- test de strlen ----\nResultado real\t|\tMi resultado\n");
    test_strlen(strlen(str), ft_strlen(str));
    free(str);
    str = strdup("");
    test_strlen(strlen(str), ft_strlen(str));
    free(str);
    str = strdup("Esto va a ser una cadena un poco mas larga de lo normal Esto va a ser una cadena un poco mas larga de lo normal");
    test_strlen(strlen(str), ft_strlen(str));
    free(str);

    // --- STRCPY --- //
    str = malloc(sizeof(char) * 11);
    printf("---- test de strcpy ----\nResultado real\t|\tMi resultado\n");
    test_strcpy(strcpy(str, "Hola Mundo"), ft_strcpy(str, "Hola Mundo"));
    free(str);
    str = malloc(sizeof(char) * 1);
    test_strcpy(strcpy(str, ""), ft_strcpy(str, ""));
    free(str);

     // --- STRCMP --- //
    printf("---- test de strcmp ----\nResultado real\t|\tMi resultado\n");
    str = strdup("Adios");
    test_strcmp(strcmp(str, "Hola Mundo"), ft_strcmp(str, "Hola Mundo"));
    free(str);
    str = strdup("");
    test_strcmp(strcmp(str, ""), ft_strcmp(str, ""));
    free(str);
    str = strdup("zzzzZzz");
    test_strcmp(strcmp(str, "zzz098"), ft_strcmp(str, "zzz098"));
    free(str);
    str = strdup("Ñ");
    test_strcmp(strcmp(str, "\n"), ft_strcmp(str, "\n"));
    free(str);

    // --- WRITE --- //
    printf("---- test de write ----\nResultado real\n-------------\nMi resultado\n\n");
    str = strdup("Adios");
    write(1, str, 5);
    printf("\n");
    ft_write(1, str, 5);
    str = strdup("Hola mundo");
    printf("\t✅\n");
    write(1, str, 1);
    printf("\n");
    ft_write(1, str, 1);
    printf("\t✅\n");

    // --- READ ---  //
    printf("---- test de read ----\n\t\t\tResultado real\t\t\t\t|\t\t\tMy resultado\n");
    printf("=============================================================================================================================\n\n");
    system("gcc read_test.c -L. -lasm -o read_test.out");
    system("./read_test.out < Makefile > my_.res");
    system("cat -e < my_.res > my.res");
    system("cat -e < Makefile > original.res");
    system("diff -y original.res my.res"); //--suppress-common-line
    system("rm -rf my_.res my.res original.res read_test.out");

	// --- STRDUP --- //
	 printf("\n\n---- test de strdup ----\nResultado real\t|\tMi resultado\n");
	str = strdup("Test 1");
	char *str2 = ft_strdup("Test 1");
	test_strdup(str, str2);
	free(str);
	free(str2);
	str = strdup("");
	str2 = ft_strdup("");
	test_strdup(str, str2);
	free(str);
	free(str2);
    return (0);
}