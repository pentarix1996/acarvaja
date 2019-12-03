/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inidata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:04:18 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/03 11:04:55 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_datatype	*inidata(t_datatype *data)
{
	data = malloc(sizeof(*data));
	data->format = "";
	data->result = 0;
	data = resetdata(data);
	return (data);
}

t_datatype	*resetdata(t_datatype *data)
{
	data->fleffield = 0;
	data->fprecision = 0;
	data->ftakearglenght = 0;
	data->ftakeargprecission = 0;
	data->fzero = 0;
	data->lenght_arg = 0;
	data->val_precission = -1;
	data->type = 0;
	data->numspaces = 0;
	data->numzeros = 0;
	data->dataupexh = 0;
	data->datapointer = -1;
	data->porcent = 0;
	data->datanbr = 0;
	data->dataunbr = 0;
	data->dataexh = 0;
	data->datastr = NULL;
	data->datachar = 0;
	data->fischar = 0;
	data->fplus = 0;
	return (data);
}
