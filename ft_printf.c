#include "ft_printf.h"


int	print_specifier(t_tag *tag, va_list ap)
{
	int	tmp_count;

	tmp_count = 0;
	if (tag->specifier == '%')
	{	
		tmp_count += 1;
		write(1, "%", 1);	
	}
	else if (tag->specifier == 'd' || tag->specifier == 'i')
		tmp_count = print_di(tag, ap);
	return (tmp_count);
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
	int		charLenght;
	int		index;

	charLenght = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			charLenght += flag_check(format, &index, ap);
		}
		else
		{
			write(1, &format[index], 1);
			charLenght++;
		}
		index++;
	}
	return (charLenght);
}

int ft_printf(const char* format, ...)
{
    int     charLenght;
    va_list ap;

    va_start(ap, format);
    charLenght = format_check((char *)format, ap);
    va_end(ap);

    return (charLenght);
}
