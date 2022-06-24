/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:11:27 by seheo             #+#    #+#             */
/*   Updated: 2022/06/24 14:02:40 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_specifier(t_tag *tag, va_list ap)
{
	int	local_cnt;

	local_cnt = 0;
	if (tag->specifier == '%')
		local_cnt = print_percent(tag);
	else if (tag->specifier == 'd' || tag->specifier == 'i')
		local_cnt = print_di(tag, ap);
	else if (tag->specifier == 'u')
		local_cnt = print_u(tag, ap);
	return (local_cnt);
}

/*

*/
int	flag_check(char *format, int *index, va_list ap)
{
	t_tag	*tag;
	int		local_cnt;

	local_cnt = 0;
	(*index)++;
	tag = malloc(sizeof(t_tag));
	init_tag(tag);
	while (ft_strchr("-0.# +123456789", format[*index]))
	{
		set_tag(tag, format, *index);
		(*index)++;
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
	{
		tag->specifier = format[*index];
		local_cnt += print_specifier(tag, ap);
	}
	free(tag);
	return (local_cnt);
}

/*
	출력하려는 문자열에 %가 있는지 없는지를 체크하여 출력하거나
	flag를 검사함 
	return : 출력 가능 문자 수
*/

int	format_check(char *format, va_list ap)
{
	int		char_lenght;
	int		index;

	char_lenght = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			char_lenght += flag_check(format, &index, ap);
		}
		else
		{
			write(1, &format[index], 1);
			char_lenght++;
		}
		index++;
	}
	return (char_lenght);
}

int	ft_printf(const	char *format, ...)
{
	int		char_lenght;
	va_list	ap;

	va_start(ap, format);
	char_lenght = format_check((char *)format, ap);
	va_end(ap);

	return (char_lenght);
}
