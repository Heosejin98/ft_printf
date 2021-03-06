/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:28:46 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 12:36:36 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di(t_tag *info, va_list ap)
{
	int	tmp_count;
	int	arg_int;

	tmp_count = 0;
	arg_int = va_arg(ap, int);
	if (info->minus > -1)//왼쪽정렬 o
	{
		tmp_count += diu_minus(arg_int);
		tmp_count += diu_str(info, arg_int);
		tmp_count += diu_space(info, arg_int);
	}
	else
	{
		tmp_count += diu_space(info, arg_int);
		tmp_count += diu_minus(arg_int);
		tmp_count += diu_zero(info, arg_int);//0 flag
		tmp_count += diu_str(info, arg_int);
	}
	return (tmp_count);
}
