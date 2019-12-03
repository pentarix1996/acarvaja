/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 08:54:05 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 10:58:38 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int result;
	int	rresult;
	//char *s_hidden = "000hi low";

	result = ft_printf("Text 1: %d\n", 0);
	rresult = printf("Text 1: %d\n", 0);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("1 **************************\n");

	result = ft_printf("Text -1: %X\n", -42);
	rresult = printf("Text -1: %X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-1 **************************\n");

	result = ft_printf("Text 2: %5X\n", 42);
	rresult = printf("Text 2: %5X\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("2**************************\n");

	result = ft_printf("Text -2: %5d\n", -42);
	rresult = printf("Text -2: %5d\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-2**************************\n");

	result = ft_printf("Text 3: %-5u\n", 42);
	rresult = printf("Text 3: %-5u\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("3**************************\n");

	result = ft_printf("Text -3: %-5X\n", -42);
	rresult = printf("Text -3: %-5X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-3**************************\n");

	result = ft_printf("Text 4: %05X\n", 42);
	rresult = printf("Text 4: %05X\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("4**************************\n");

	result = ft_printf("Text -4: %05X\n", -42);
	rresult = printf("Text -4: %05X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-4**************************\n");

	result = ft_printf("Text 5: %05.i\n", 42);
	rresult = printf("Text 5: %05.i\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("5**************************\n");

	result = ft_printf("Text -5: %-5.i\n", -42);
	rresult = printf("Text -5: %-5.i\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-5**************************\n");

	result = ft_printf("Text 6: %7.5d\n", 42);
	rresult = printf("Text 6: %7.5d\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("6**************************\n");

	result = ft_printf("Text -6: %7.5X\n", -42);
	rresult = printf("Text -6: %7.5X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-6**************************\n");

	result = ft_printf("Text 7: %5.7X\n", 42);
	rresult = printf("Text 7: %5.7X\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("7**************************\n");

	result = ft_printf("Text -7: %5.7X\n", -42);
	rresult = printf("Text -7: %5.7X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-7**************************\n");

	result = ft_printf("Text 8: %-7.5X\n", 42);
	rresult = printf("Text 8: %-7.5X\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("8**************************\n");

	result = ft_printf("Text -8: %-7.5X\n", -42);
	rresult = printf("Text -8: %-7.5X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-8**************************\n");

	result = ft_printf("Text 9: %.5u\n", 42);
	rresult = printf("Text 9: %.5u\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("9*************************\n");

	result = ft_printf("Text -9: %.5i\n", -42);
	rresult = printf("Text -9: %.5i\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-9**************************\n");

	result = ft_printf("Text 10: %07.5d\n", 42);
	rresult = printf("Text 10: %07.5d\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("10**************************\n");

	result = ft_printf("Text -10: %07.5X\n", -42);
	rresult = printf("Text -10: %07.5X\n", -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-10**************************\n");

	result = ft_printf("Text 11: %0*.5x\n", 7, 42);
	rresult = printf("Text 11: %0*.5x\n", 7, 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("11**************************\n");

	result = ft_printf("Text -11: %0*.5X\n", 7, -42);
	rresult = printf("Text -11: %0*.5X\n", 7, -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-11**************************\n");

	result = ft_printf("Text 12: %03.*X\n", 2, 42);
	rresult = printf("Text 12: %03.*X\n", 2, 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("12**************************\n");

	result = ft_printf("Text -12: %03.*X\n", 2, -42);
	rresult = printf("Text -12: %03.*X\n", 2, -42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("-12**************************\n");

	result = ft_printf("Text 13: %0*.*x\n", 3, 2, 43232);
	rresult = printf("Text 13: %0*.*x\n", 3, 2, 43232);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("13**************************\n");

	result = ft_printf("Text -13: %% yes\n");
	rresult = printf("Text -13: %% yes\n");
	printf("Real --> %d VS %d\n", rresult, result);
	printf("14**************************\n");

	result = ft_printf("Text -13: %-05% yes\n");
	rresult = printf("Text -13: %-05% yes\n");
	printf("Real --> %d VS %d\n", rresult, result);
	printf("15**************************\n");

	//char *mx_s = "Hello, World!";
	//char mx_c = 0;
	
	result = ft_printf("%+5d\n", 42);
	rresult = printf("%+5d\n", 42);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("16**************************\n");

	//printf(" %d |",    printf("1 %% %%%% %%%%%% %c %c %c %c%% 0%c 0%c %c %c %s %s%% %s %s %i %i %i %i %i %i %i %i %i %i %d %d %d %d %d %d %d %d %d %d %u %u %u %u %u %u %u %x %x %x %x %x %x %x %x %x %x %X %X %X %X %X %X %X %X %X %X %p %p %p %p %p %p\n\n", '1', -207, 256 + 48, '3', 0, -129, 128, '\0', "hello", "hello3", "", "1", 0, -1, -42, 1, 2, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, 0 , -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, 0, -1, 1, 42, UINT_MAX, UINT_MAX + 1, 1000, 0, -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, 0, -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, (void*)1, (void*)-1, (void*)42, (void*)1000,  (void*)ULONG_MAX, (void*)ULONG_MAX + 1));
    //printf(" %d\n", ft_printf("1 %% %%%% %%%%%% %c %c %c %c%% 0%c 0%c %c %c %s %s%% %s %s %i %i %i %i %i %i %i %i %i %i %d %d %d %d %d %d %d %d %d %d %u %u %u %u %u %u %u %x %x %x %x %x %x %x %x %x %x %X %X %X %X %X %X %X %X %X %X %p %p %p %p %p %p\n\n", '1', -207, 256 + 48, '3', 0, -129, 128, '\0', "hello", "hello3", "", "1", 0, -1, -42, 1, 2, INT_MAX, (INT_MAX + 1), INT_MIN, 1000, -1000, 0 , -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, 0, -1, 1, 42, UINT_MAX, UINT_MAX + 1, 1000, 0, -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, 0, -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, (void*)1, (void*)-1, (void*)42, (void*)1000,  (void*)ULONG_MAX, (void*)ULONG_MAX + 1));
    //printf("%d |", printf("%x %x\n", 1000, -1000));
    //printf("%d", ft_printf("%x %x\n", 1000, -1000));
    //printf(" %d |",    printf("A %x %x %x %x %x %x %x %x %x %x %X %X %X %X %X %X %X %X %X %X %p %p %p %p %p %p", 0, -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, (void*)1, (void*)-1, (void*)42, (void*)1000,  (void*)ULONG_MAX, (void*)ULONG_MAX + 1));
    //printf(" %d\n", ft_printf("B %x %x %x %x %x %x %x %x %x %x %X %X %X %X %X %X %X %X %X %X %p %p %p %p %p %p", 0, -1, -42, 1, 42, INT_MAX, INT_MAX + 1, INT_MIN, 1000, -1000, (void*)1, (void*)-1, (void*)42, (void*)1000,  (void*)ULONG_MAX, (void*)ULONG_MAX + 1));
    //ft_printf("\n\n%x %x %x %x %x %x %x %x %x %x", 0, -1, -2, -3, -4, -5, -6, -7, -8, -9);
    //ft_printf("\n\n%X %X %X %X %X %X %X %X %X %X", 10, 11, 12, 13, 14, 15, 16, 17, 18, 19);
    //ft_printf("\n\n%p %p %p %p %p %p %p %p %p %p", (void*)10, (void*)1, (void*)1, (void*)1, (void*)1, (void*)1, (void*)1, (void*)1, (void*)1, (void*)10);
    //ft_printf("\n\n%c %c %c %c %c %c %c %c %c %c", 97, 97, 97, 97, 97, 97, 97, 97, 97, 97);

	return (0);
}
