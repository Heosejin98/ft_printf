#include "ft_printf.h"

void	init_tag(t_tag *tag)
{
	tag->hash = -1;
	tag->minus = -1;
	tag->period = -1;
	tag->plus = -1;
	tag->space = -1;
	tag->specifier = -1;
	tag->zero = -1;
	tag->width = 0;
	tag->precision = 0; 
}


char	*ft_strchr(const char *str, int c)
{
	char	*ptr_str;
	char	to_find;

	ptr_str = (char *)str;
	to_find = (char)c;
	while (*ptr_str)
	{
		if (*ptr_str == to_find)
			return (ptr_str);
		else
			ptr_str++;
	}
	if (to_find == '\0')
		return (ptr_str);
	return (NULL);
}

int	if_get_zero(t_tag *tag, int index)
{
	if (tag->period > -1)
		tag->precision = tag->precision * 10;
	else if (tag->width)
		tag->width = tag->width * 10;
	else
		tag->zero = index;
	return (1);
}


int	set_tag(t_tag *tag, char *format, int index)
{
	if (ft_strchr("0", format[index]))
		return (if_get_zero(tag, index));
	if (ft_strchr("-.# +", format[index]))
	{
		if (format[index] == '-')
			tag->minus = index;
		else if (format[index] == '.')
			tag->period = index;
		else if (format[index] == '#')
			tag->hash = index;
		else if (format[index] == ' ')
			tag->space = index;
		else if (format[index] == '+')
			tag->plus = index;
		return (1);
	}
	if (ft_strchr("123456789", format[index]))
	{
		if (tag->period > -1)
			tag->precision = (tag->precision * 10) + (format[index] - '0');
		else
			tag->width = (tag->width * 10) + (format[index] - '0');
		return (1);
	}
	return (0);
}