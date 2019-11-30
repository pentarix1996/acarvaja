/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:18:10 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/30 10:17:16 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

t_datatype	*resetdata(t_datatype *data)
{
	data->fleffield = 0;
	data->fprecision = 0;
	data->ftakearglenght = 0;
	data->ftakeargprecission = 0;
	data->fzero = 0;
	data->lenght_arg = 0;
	data->val_precission = 0;
	data->type = 0;
	data->numspaces = 0;
	data->datanbr = 0;
	data->dataunbr = 0;
	data->dataexh = 0;
	data->numzeros = 0;
	data->dataupexh = 0;
	data->datapointer = -1;
	return (data);
}

int			do_complex(t_datatype *data, va_list ap)
{
	data->result = 0;
	next_type(data);
	data->format++;
	while (*data->format)
	{
		while (is_flag(*data->format))
			data->format += read_flag(data, ap);
		if ((data->type = is_correct_type(*data->format)))
		{
			if (is_numerical_type(data->type))
			{
				if (do_num_type(data, ap) == -1)
					return (-1);
			}
			else
			{
				if (do_str_type(data, ap) == -1)
					return (-1);
			}
			data->format += 1;
		}
		data = resetdata(data);
		next_type(data);
		if (*data->format)
			data->format++;
	}
	va_end(ap);
	return (data->result);
}

int			do_simple(const char *format)
{
	ft_putstr(format);
	return (ft_strlen(format));
}

int			is_simple(const char *format)
{
	return (!(ft_strchr(format, percent)) ? 1 : 0);
}

t_datatype	*inidata(t_datatype *data)
{
	data = malloc(sizeof(*data));
	data->format = "";
	data->result = 0;
	data = resetdata(data);
	return (data);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_datatype	*data;
	int result;

	data = 0;
	data = inidata(data);
	data->format = (char *)format;
	va_start(ap, format);
	if (!is_simple(format))
		result = do_complex(data ,ap);
	free(data);
	return (is_simple(format) ? do_simple(format) : result);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int result;
	int	rresult;
	char *str = "Hello World";

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

	result = ft_printf("Text -5: %05.i\n", -42);
	rresult = printf("Text -5: %05.i\n", -42);
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

	result = ft_printf("Text -13: %p yes\n", str);
	rresult = printf("Text -13: %p yes\n", str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("14**************************\n");

	result = ft_printf("Text -13: %12p yes\n", str);
	rresult = printf("Text -13: %12p yes\n", str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("15**************************\n");

	result = ft_printf("Text -13: %-12p yes\n", str);
	rresult = printf("Text -13: %-12p yes\n", str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("16**************************\n");

	/*result = ft_printf("Text -13: %12.6p yes\n", str);
	rresult = printf("Text -13: %12.6p yes\n", str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("17**************************\n");

	result = ft_printf("Text -13: %-12.6p yes\n", str);
	rresult = printf("Text -13: %-12.6p yes\n", str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("18**************************\n");

	result = ft_printf("Text -13: %*.7p yes\n", 3, str);
	rresult = printf("Text -13: %*.7p yes\n", 3, str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("19**************************\n");

	result = ft_printf("Text -13: %9.*p yes\n", 4, str);
	rresult = printf("Text -13: %9.p* yes\n", 4, str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("20**************************\n");

	result = ft_printf("Text -13: %*.*p yes\n", 7, 4, str);
	rresult = printf("Text -13: %*.*p yes\n", 7, 4, str);
	printf("Real --> %d VS %d\n", rresult, result);
	printf("21**************************\n");*/
	return (0);
}
