#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int a = ft_printf("%10.5dasd\n", -123);
    int b = ft_printf("%10.5dasd\n", -123);
    printf("return : %d \n", a);
    printf("return : %d \n", b);

    a = ft_printf("%.5dasd\n", -123);
    b = printf("%.5dasd\n", -123);

    printf("return : %d \n", a);
    printf("return : %d \n", b);

    a = ft_printf("%5dasd\n", -123);
    b = printf("%5dasd\n", -123);
    
    printf("return : %d \n", a);
    printf("return : %d \n", b);

    a = ft_printf("%-0.dasd\n", 123);
    b = printf("%-0.dasd\n", 123);
    printf("return : %d \n", a);
    printf("return : %d \n", b);

    a = ft_printf("%+0.dasd\n", 123);
    b= printf("%+0.dasd\n", 123);
    printf("return : %d \n", a);
    printf("return : %d \n", b);

    a = ft_printf("%+0.dasd\n", 123);
    b = printf("%+0.dasd\n", 123);  
    printf("return : %d \n", a);
    printf("return : %d \n", b); 

    a = ft_printf("%010dasd\n", 123);
    b = printf("%010dasd\n", 123);  
    
    printf("return : %d \n", a);
    printf("return : %d \n", b); 

    a = ft_printf("%010uasd\n", 2323);
    b = printf("%010uasd\n", 2323);  
    printf("return : %d \n", a);
    printf("return : %u \n", b); 


    printf("\n----------------------------------------\n"); 

    a = ft_printf("%010uasd\n", 2323);
    b = printf("%010uasd\n", 2323);  
    printf("return : %d \n", a);
    printf("return : %d \n", b);

    a = ft_printf("%010uasd\n", -2323);
    b = printf("%010uasd\n", -2323); 
    printf("return : %d \n", a);
    printf("return : %d \n", b);


    a = ft_printf("%u\n", 2323);
    b = printf("%u\n", 2323);  
    printf("return : %d \n", a);
    printf("return : %d \n", b);

    printf("%-010%\n");
}