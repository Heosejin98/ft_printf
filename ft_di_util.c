/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:16:42 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 12:36:00 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//숫자 출력 정밀도체크
int	diu_number(t_tag *tag, long arg_int)
{
	int	count;

	count = get_nbrlen(arg_int);
	if (arg_int < 0)
	{
		count--;
	}
	while (tag->precision > count)
	{
		write(1, "0", 1);
		count++;
	}
	if (arg_int == 0 && tag->period > -1)
	{
		if (!tag->precision && tag->width)
			write(1, " ", 1);
		else if (tag->precision)
			write(1, "0", 1);
		else
			count--;
	}
	else
		ft_putnbr(arg_int);
	return (count);
}

//공백 + 기호 등 출력
int	diu_str(t_tag *tag, long arg_int)
{
	int	count;

	count = 0;
	if (tag->plus > -1 && arg_int > -1 && tag->specifier != 'u')
	{
		write(1, "+", 1);
		count++;
	}
	else if (tag->space > -1 && arg_int > -1 && tag->specifier != 'u')
	{
		write(1, " ", 1);
		count++;
	}
	count += diu_number(tag, arg_int);
	return (count);
}

//넓이체크
int	diu_space(t_tag *tag, long arg_int)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = get_nbrlen(arg_int);//자릿수 
	if (tag->precision >= arg_size)//정밀도가 있는경우
	{
		arg_size = tag->precision;
		if (arg_int < 0) 
			arg_size++;
	}
	if ((arg_int > 0) && (tag->space > -1 || tag->plus > -1)) //공백 + 있으면
		arg_size++;
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

//0 flag 체크
int	diu_zero(t_tag *tag, long arg_int)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = get_nbrlen(arg_int);
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

//음수체크
int	diu_minus(long arg_int)
{
	int	count;

	count = 0;
	if (arg_int < 0)
	{
		write(1, "-", 1);
		count++;
	}
	return (count);
}
