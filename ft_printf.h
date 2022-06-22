#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct fomat_tag
{
	char		specifier; //서식문자
	int			minus; // -
	int			zero; // 0 
	int			period; // 
	int			hash; // #
	int			space; // 공백
	int			plus; // + 
	int			width; //넓이 
	int			precision; //정밀도
}				f_tag;

//ft_printf
int		flag_check(char *format, int *index, va_list ap);
int		ft_printf(const char* format, ...);
int		format_check(char *format, va_list ap);

//ft_tag
void	init_tag(f_tag *tag);
int	    setFtag(f_tag *tag, char *format, int index);
char    *ft_strchr(const char *str, int c);

//ft_specifier_di
int		print_di(f_tag *tag, va_list ap);
int		print_di_putnbr(f_tag *tag, long arg_int);
int		print_di_putstr(f_tag *tag, long arg_int);
int		print_di_putspace(f_tag *tag, long arg_int);
int		print_di_putzero(f_tag *tag, long arg_int);
int		print_di_putminus(long arg_int);

//ft_number
int		get_nbrlen(long n);
void	ft_putnbr(long n);



#endif