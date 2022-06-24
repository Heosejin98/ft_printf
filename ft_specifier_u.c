/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:52:36 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 13:56:15 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(t_tag *info, va_list ap)
{
	int		local_cnt;
	long	arg_int;

	local_cnt = 0;
	arg_int = va_arg(ap, unsigned int);
	if (info->minus > -1)
	{
		local_cnt += diu_minus(arg_int);
		local_cnt += diu_str(info, arg_int);
		local_cnt += diu_space(info, arg_int);
	}
	else
	{
		local_cnt += diu_space(info, arg_int);
		local_cnt += diu_minus(arg_int);
		local_cnt += diu_zero(info, arg_int);
		local_cnt += diu_str(info, arg_int);
	}
	return (local_cnt);
}
