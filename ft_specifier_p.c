/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:32:31 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 16:55:53 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_p(t_tag *tag, va_list ap)
{
	int				local_count;
	unsigned long long	args_ulong;

	local_count = 0;
	
    
	args_ulong = (unsigned long long)va_arg(ap, void *);
		
	if (tag->minus > -1)
	{
		local_count += xX_hash(tag, args_ulong);
		local_count += xX_print(tag, args_ulong);
		local_count += xX_space(tag, args_ulong);
	}
	else
	{
		local_count += xX_space(tag, args_ulong);
		local_count += xX_hash(tag, args_ulong);
		local_count += xX_zero(tag, args_ulong);
		local_count += xX_print(tag, args_ulong);
	}
	local_count++;
	return (local_count - 1);
}