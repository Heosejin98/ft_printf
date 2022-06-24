/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_persent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:00:48 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 14:26:47 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int percent_spacezero(t_tag *tag)
{
	int count;

	count = 1;
	if (tag->zero > -1 && !(tag->minus > -1))
	{
		while (tag->width > count++)
		{
			write(1, "0", 1);
		}
	}
	else
	{
		while (tag->width > count++)
			write(1, " ", 1);
	}
	return (count - 1);
}

int	print_percent(t_tag *tag)
{
	int	local_count;

	local_count = 0;
	if (tag->minus > -1)
	{
		write(1, "%", 1);
		local_count += percent_spacezero(tag);
	}
	else
	{
		local_count += percent_spacezero(tag);
		write(1, "%", 1);
	}
	return (local_count);
}
