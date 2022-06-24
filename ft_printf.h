#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_fomat_tag
{
	char	specifier;
	int		minus;
	int		zero;
	int		period;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
}				t_tag;

//ft_printf
int		flag_check(char *format, int *index, va_list ap);
int		ft_printf(const char *format, ...);
int		format_check(char *format, va_list ap);

int		print_di(t_tag *tag, va_list ap);
int		print_u(t_tag *tag, va_list ap);

//ft_tag
void	init_tag(t_tag *tag);
int		set_tag(t_tag *tag, char *format, int index);
char	*ft_strchr(const char *str, int c);

//ft_di_util
int		diu_number(t_tag *tag, long arg_int);
int		diu_str(t_tag *tag, long arg_int);
int		diu_space(t_tag *tag, long arg_int);
int		diu_zero(t_tag *tag, long arg_int);
int		diu_minus(long arg_int);

//ft_number_util
int		get_nbrlen(long n);
void	ft_putnbr(long n);

#endif