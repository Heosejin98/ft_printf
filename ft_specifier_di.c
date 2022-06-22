#include "ft_printf.h"


int	print_di_putnbr(f_tag *info, long arg_int)
{
	int	count;

	count = get_nbrlen(arg_int);
	if (arg_int < 0)
	{
		count--;
	}
	while (info->precision > count)
	{
		write(1, "0", 1);
		count++;
	}
	if (arg_int == 0 && info->period > -1)
	{
		if (!info->precision && info->width)
			write(1, " ", 1);
		else if (info->precision)
			write(1, "0", 1);
		else
			count--;
	}
	else
		ft_putnbr(arg_int);
	return (count);
}

int	print_di_putstr(f_tag *info, long arg_int)
{
	int	count;

	count = 0;
	if (info->plus > -1 && arg_int > -1 && info->specifier != 'u')
	{
		write(1, "+", 1);
		count++;
	}
	else if (info->space > -1 && arg_int > -1 && info->specifier != 'u')
	{
		write(1, " ", 1);
		count++;
	}
	count += print_di_putnbr(info, arg_int);
	return (count);
}

int	print_di_putspace(f_tag *info, long arg_int)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = get_nbrlen(arg_int);
	if (info->precision >= arg_size)
	{
		arg_size = info->precision;
		if (arg_int < 0)
			arg_size++;
	}
	if ((arg_int > 0) && (info->space > -1 || info->plus > -1))
		arg_size++;
	if (info->zero > -1 && (info->minus > -1 || info->period > -1))
	{
		while (info->width > arg_size++ && count++)
			write(1, " ", 1);
	}
	else if (info->zero == -1)
	{
		while (info->width > arg_size++ && count++)
			write(1, " ", 1);
	}
	return (count - 1);
}

int	print_di_putzero(f_tag *info, long arg_int)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = get_nbrlen(arg_int);
	if (info->precision > arg_size)
		arg_size = info->precision;
	if (info->zero > -1 && !(info->period > -1 || info->minus > -1))
	{
		while (info->width > arg_size++)
		{
			write(1, "0", 1);
			count++;
		}
	}
	return (count);
}

int	print_di_putminus(long arg_int)
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

int	print_di(f_tag *info, va_list ap)
{
	int	tmp_count;
	int	arg_int;

	tmp_count = 0;
	arg_int = va_arg(ap, int);
	if (info->minus > -1)
	{
		tmp_count += print_di_putminus(arg_int);
		tmp_count += print_di_putstr(info, arg_int);
		tmp_count += print_di_putspace(info, arg_int);
	}
	else
	{
		tmp_count += print_di_putspace(info, arg_int);
		tmp_count += print_di_putminus(arg_int);
		tmp_count += print_di_putzero(info, arg_int);
		tmp_count += print_di_putstr(info, arg_int);
	}
	return (tmp_count);
}
