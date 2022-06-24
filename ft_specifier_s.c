/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:40:19 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 14:47:02 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(t_tag *tag, const char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		str++;
		length++;
	}
	if (tag->period > -1 && tag->precision == 0)
		length = 0;
	else if (tag->precision && length > tag->precision)
		length = tag->precision;
	return (length);
}

int	s_zero(t_tag *tag, char *arg_char)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = ft_strlen(tag, arg_char);
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

int	s_space(t_tag *tag, char *arg_char)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = ft_strlen(tag, arg_char);
	if (tag->zero > -1 && tag->minus > -1)
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

int	ft_putstr(char *s, int size)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (size > count)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count - 1);
}

int	print_s(t_tag *tag, va_list ap)
{
	int		local_count;
	char	*arg_char;

	local_count = 0;
	arg_char = va_arg(ap, char *);
	if (arg_char == NULL)
		arg_char = "(null)";
	if (tag->minus > -1)
	{
		local_count += ft_putstr(arg_char, ft_strlen(tag, arg_char));
		local_count += s_space(tag, arg_char);
	}
	else
	{
		local_count += s_space(tag, arg_char);
		local_count += s_zero(tag, arg_char);
		local_count += ft_putstr(arg_char, ft_strlen(tag, arg_char));
	}
	local_count++;
	return (local_count);
}
