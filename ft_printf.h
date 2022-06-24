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
int		print_c(t_tag *tag, va_list ap);
int		print_percent(t_tag *tag);
int		print_s(t_tag *tag, va_list ap);
int		print_xX(t_tag *tag, va_list ap);

//ft_tag
void	init_tag(t_tag *tag);
int		set_tag(t_tag *tag, char *format, int index);
char	*ft_strchr(const char *str, int c);

//util
int		diu_number(t_tag *tag, long arg_int);
int		diu_str(t_tag *tag, long arg_int);
int		diu_space(t_tag *tag, long arg_int);
int		diu_zero(t_tag *tag, long arg_int);
int		diu_minus(long arg_int);
int		c_zero(t_tag *tag);
int		c_space(t_tag *tag);
int		ft_strlen(t_tag *tag, const char *str);
int		s_zero(t_tag *tag, char *arg_char);
int		s_space(t_tag *tag, char *arg_char);
int		ft_putstr(char *s, int size);
int		percent_spacezero(t_tag *tag);
int		xX_print(t_tag *tag, unsigned long long arg_uint);
int		xX_space(t_tag *tag, long arg_uint);
int		xX_hash(t_tag *tag, long arg_uint);
int		xX_zero(t_tag *tag, unsigned int arg_uint);

//ft_number_util
int		get_nbrlen(long n);
void	ft_putnbr(long n);
int		get_hexa_len(t_tag *tag, unsigned long long n);
void	ft_puthexa(unsigned long long n, char type);

#endif