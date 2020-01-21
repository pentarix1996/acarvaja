#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int i, j;
	i = printf("A ver: [%1.15d]\n", 0);
   	j = ft_printf("A ver: [%1.15d]\n", 0);
	printf("Real: [%d] vs Mia: [%d]\n", i, j);
	return (0);
}
