/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_xX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:28:48 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 16:10:44 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xX_print(t_tag *tag, unsigned long long arg_uint)
{
	int	count;

	count = get_hexa_len(tag, arg_uint);
	while (tag->precision > count)
	{
		write(1, "0", 1);
		count++;
	}
	if (arg_uint == 0 && tag->period > -1)
	{
		if (tag->precision)
			write(1, "0", 1);
	}
	else
		ft_puthexa(arg_uint, tag->specifier);
	return (count);
}

int	xX_space(t_tag *tag, long arg_uint)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = get_hexa_len(tag, arg_uint);
	if (tag->precision > arg_size)
		arg_size = tag->precision;
	if (tag->hash > -1 || tag->specifier == 'p')
		arg_size = arg_size + 2;
	if (tag->zero > -1 && (tag->minus > -1 || tag->period > -1))
	{
		while (tag->width > arg_size++ && count++)
			write(1, " ", 1);
	}
	else if (tag->zero == -1)
	{
		while (tag->width > arg_size++ && count++)
			write(1, " ", 1);
	}
	return (count - 1);
}

int	xX_hash(t_tag *tag, long arg_uint)
{
	int	count;

	count = 0;
	if ((arg_uint != 0 && tag->hash > -1) || tag->specifier == 'p')
	{
		if (tag->specifier == 'x' || tag->specifier == 'p')
		{
			write(1, "0x", 2);
			count = 2;
		}
		else if (tag->specifier == 'X')
		{
			write(1, "0X", 2);
			count = 2;
		}
	}
	return (count);
}

int	xX_zero(t_tag *tag, unsigned int arg_uint)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = get_hexa_len(tag, arg_uint);
	if (tag->precision > arg_size)
		arg_size = tag->precision;
	if (tag->zero > -1 && !(tag->period > -1 || tag->minus > -1))
	{
		while (tag->width > arg_size++)
		{
			write(1, "0", 1);
			count++;
		}
	}
	return (count);
}

int	print_xX(t_tag *tag, va_list ap)
{
	int				local_count;
	unsigned int	arg_uint;

	local_count = 0;
	arg_uint = va_arg(ap, unsigned int);

	if (tag->minus > -1)
	{
		local_count += xX_hash(tag, arg_uint);
		local_count += xX_print(tag, arg_uint);
		local_count += xX_space(tag, arg_uint);
	}
	else
	{
		local_count += xX_space(tag, arg_uint);
		local_count += xX_hash(tag, arg_uint);
		local_count += xX_zero(tag, arg_uint);
		local_count += xX_print(tag, arg_uint);
	}
	local_count++;
	return (local_count);
}