/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:50:29 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 15:24:32 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_zero(t_tag *tag)
{
	int	local_count;
	int	arg_size;

	local_count = 0;
	arg_size = 1;
	if (tag->zero > -1 && !(tag->period > -1 || tag->minus > -1))
	{
		while (tag->width > arg_size++)
		{
			write(1, "0", 1);
			local_count++;
		}
	}
	return (local_count);
}

int	c_space(t_tag *tag)
{
	int	local_count;
	int	arg_size;

	local_count = 1;
	arg_size = 1;
	if (tag->zero > -1 && tag->minus > -1)
	{
		while (tag->width > arg_size++ && local_count++)
			write(1, " ", 1);
	}
	else if (tag->zero == -1)
	{
		while (tag->width > arg_size++ && local_count++)
			write(1, " ", 1);
	}
	return (local_count - 1);
}

int	print_c(t_tag *tag, va_list ap)
{
	int				local_count;
	unsigned char	arg_char;

	local_count = 0;
	arg_char = (unsigned char)va_arg(ap, int);
	if (tag->minus > -1)
	{
		write(1, &arg_char, 1);
		local_count += c_space(tag);
	}
	else
	{
		local_count += c_space(tag);
		local_count += c_zero(tag);
		write(1, &arg_char, 1);
	}
	local_count++;
	return (local_count);
}
