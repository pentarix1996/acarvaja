/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:22:28 by acarvaja          #+#    #+#             */
/*   Updated: 2019/11/30 09:52:33 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum 		e_types
{
	string		= 's',
	character	= 'c',
	pointer		= 'p',
	decimal		= 'd',
	integer		= 'i',
	unsgint		= 'u',
	exhlower	= 'x',
	exhupper	= 'X',
	percent		= '%'
}					t_types;

typedef enum		e_flags
{
	zero		= '0',
	leffield	= '-',
	takearg		= '*',
	precision	= '.',
}					t_flags;

typedef struct		s_datatype
{
	int				fzero;
	int				fleffield;
	int				ftakearglenght;
	int				ftakeargprecission;
	int				fprecision;
	int				lenght_arg;
	int				result;
	int				val_precission;
	int				type;
	int				numspaces;
	int				numzeros;
	int				datanbr;
	unsigned int	dataunbr;
	unsigned long	dataexh;
	unsigned long	dataupexh;
	long			datapointer;
	char			*datastr;
	char			datachar;
	char			*format;
}					t_datatype;

int			ft_printf(const char *format, ...);
void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		next_type(t_datatype *data);
int			is_correct_type(char type);
int			is_numerical_type(char type);
int			do_str_type(t_datatype *data, va_list ap);
int			do_num_type(t_datatype *data, va_list ap);
int			is_flag(char flag);
int			read_flag(t_datatype *data, va_list ap);

#endif
