/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:22:28 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/12 00:21:43 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef enum		e_types
{
	string = 's',
	character = 'c',
	pointer = 'p',
	decimal = 'd',
	integer = 'i',
	unsgint = 'u',
	exhlower = 'x',
	exhupper = 'X',
	percent = '%',
}					t_types;

typedef enum		e_flags
{
	zero = '0',
	leffield = '-',
	takearg = '*',
	precision = '.',
	plus = '+',
	space = ' '
}					t_flags;

typedef struct		s_datatype
{
	int				fzero;
	int				fleffield;
	int				fprecision;
	int				lenght_arg;
	int				result;
	int				val_precission;
	int				type;
	int				numspaces;
	int				numzeros;
	int				datanbr;
	int				fischar;
	int				fplus;
	int				fpointer;
	int				fuint;
	int				fspace;
	int				fpercent;
	unsigned int	dataunbr;
	unsigned int	dataexh;
	unsigned int	dataupexh;
	long			datapointer;
	int				porcent;
	char			*datastr;
	char			datachar;
	char			*format;
}					t_datatype;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				next_type(t_datatype *data);
int					is_correct_type(char type);
int					is_numerical_type(char type);
int					do_str_type(t_datatype *data, va_list ap);
int					do_num_type(t_datatype *data, va_list ap);
int					is_flag(char flag);
int					read_flag(t_datatype *data, va_list ap);
t_datatype			*resetdata(t_datatype *data);
t_datatype			*inidata(t_datatype *data);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putnstr(const char *str, int i);
void				ft_putunbr(unsigned int nb);
void				ft_putnbr(int nb, int singneg);
void				next_type(t_datatype *data);
t_types				*fill_types(t_types *my_list_types);
int					is_correct_type(char type);
int					is_numerical_type(char type);
int					is_flag(char flag);
void				ft_swap(char *a, char *b);
char				*revert(char *ptr);
char				*ft_atoa_lowexh(unsigned long nbr);
char				*ft_atoa_upperexh(unsigned long nbr);
int					ft_generallen(t_datatype *data);
long				generalnbr(t_datatype *data);
void				ft_printstr(t_datatype *data);
void				ft_putgeneral(t_datatype *data, int negativesign,
						va_list ap);
int					ft_intlen(long nbr);
int					ft_uintlen(unsigned int nbr);
void				print_spaces(t_datatype *data);
void				print_zeros(t_datatype *data);
void				ft_printfnbr(t_datatype *data, va_list ap);
void				calc_numspaces(t_datatype *data);
void				do_num_dandi(t_datatype *data, va_list ap);
void				do_num_u(t_datatype *data, va_list ap);
void				do_num_exhl(t_datatype *data, va_list ap);
void				do_num_exhu(t_datatype *data, va_list ap);
int					do_num_type(t_datatype *data, va_list ap);
void				numspaces_casefp(t_datatype *data);
void				numspaces_casenegp(t_datatype *data);
void				numspaces_pointer(t_datatype *data);
void				calc_numspaces(t_datatype *data);
void				do_str_str(t_datatype *data, va_list ap);
int					do_str_type(t_datatype *data, va_list ap);
void				ft_print_nzp(t_datatype *data, va_list ap);
void				ft_print_znpl(t_datatype *data, va_list ap);
void				ft_print_pvpla(t_datatype *data, va_list ap);
void				ft_print_lvpp(t_datatype *data, va_list ap);
void				ft_print_zl(t_datatype *data, va_list ap);
void				ft_printchar(va_list ap);
void				calc_spaces_fspc(t_datatype *data);

#endif
