#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("%10.5dasd\n", -123);
    printf("%10.5dasd\n", -123);

    ft_printf("%.5dasd\n", -123);
    printf("%.5dasd\n", -123);

    ft_printf("%5dasd\n", -123);
    printf("%5dasd\n", -123);

    ft_printf("%-0.dasd\n", 123);
    printf("%-0.dasd\n", 123);

    ft_printf("%+0.dasd\n", 123);
    printf("%+0.dasd\n", 123);

    ft_printf("%+0.dasd\n", 123);
    printf("%+0.dasd\n", 123);   

    ft_printf("%010dasd\n", 123);
    printf("%010dasd\n", 123);   
}