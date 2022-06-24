/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:40:53 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 16:54:29 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int	get_hexa_len(t_tag *tag, unsigned long long n)
{
	int		len;

	len = 0;
	if (n == 0 && tag->period > -1 && !(tag->precision))
		return (0);
	else if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_puthexa(unsigned long long n, char type)
{
	char	c;

	if (n >= 16)
	{
		ft_puthexa((n / 16), type);
		if ((n % 16) >= 10 && (type == 'x' || type == 'p'))
			c = 'a' + (n % 16) - 10;
		else if ((n % 16) >= 10 && type == 'X')
			c = 'A' + (n % 16) - 10;
		else
			c = '0' + (n % 16);
		write(1, &c, 1);
	}
	else
	{
		if ((n % 16) >= 10 && (type == 'x' || type == 'p'))
			c = 'a' + (n % 16) - 10;
		else if ((n % 16) >= 10 && type == 'X')
			c = 'A' + (n % 16) - 10;
		else
			c = '0' + (n % 16);
		write(1, &c, 1);
	}
}