#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("width + precision + d\n");
    int a = ft_printf("%10.5dasd\n", -123);
    int b = ft_printf("%10.5dasd\n", -123);
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("precision + d\n");
    a = ft_printf("%.5dasd\n", -123);
    b = printf("%.5dasd\n", -123);
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("space + d\n");
    a = ft_printf("% 5dasd\n", -123);
    b = printf("% 5dasd\n", -123);
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("-0.d\n");
    a = ft_printf("%-0.dasd\n", 123);
    b = printf("%-0.dasd\n", 123);
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("plus + zero + precision + d\n");
    a = ft_printf("%+0.dasd\n", 123);
    b= printf("%+0.dasd\n", 123);
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("zero + width d\n");
    a = ft_printf("%010dasd\n", 123);
    b = printf("%010dasd\n", 123);  
    printf("return : %d \n", a);
    printf("return : %d \n\n", b); 

    printf("\n------------------u---------------------\n"); 
    printf("zero + width + u\n");
    a = ft_printf("%010uasd\n", 2323);
    b = printf("%010uasd\n", 2323);  
    printf("return : %d \n", a);
    printf("return : %u \n\n", b); 

    printf("zero + width + u (u가 음수인 경우)\n");
    a = ft_printf("%010uasd\n", -2323);
    b = printf("%010uasd\n", -2323); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("u\n");
    a = ft_printf("%u\n", 2323);
    b = printf("%u\n", 2323);  
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("- + zero + u \n");
    a = ft_printf("%-010uasd\n", 2323);
    b = printf("%-010uasd\n", 2323); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("\n---------------------%%------------------\n"); 
    printf("width + %% \n");
    a = ft_printf("%10%\n");
    b = printf("%10%\n");  
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("'-' + width + %% \n");
    a = ft_printf("%-10%\n");
    b = printf("%-10%\n");  
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);


    printf("\n---------------------c------------------\n"); 
    printf(" c \n");
    a = ft_printf("1 %c\n", 'a');
    b = printf("2 %c\n", 'a'); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("width + c \n");
    a = ft_printf("1 %10c\n", 'a');
    b = printf("2 %10c\n", 'a'); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("'-' + width + c \n");
    a = ft_printf("1 %-10c\n", 'a');
    b = printf("2 %-10c\n", 'a'); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("'0' + width + c \n");
    a = ft_printf("1 %010c\n", 'a');
    b = printf("2 %010c\n", 'a'); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("\n---------------------s------------------\n");
    a = ft_printf("1 %s\n", "test"); 
    b = printf("2 %s\n", "test"); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);


    a = ft_printf("1 %-10s\n", "test"); 
    b = printf("2 %-10s\n", "test"); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    a = ft_printf("1 %10s\n", "test"); 
    b = printf("2 %10s\n", "test"); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    a = ft_printf("1 %10.2s\n", "test"); 
    b = printf("2 %10.2s\n", "test"); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);

    printf("\n---------------------x------------------\n");
    a = ft_printf("1 %x\n", 1232); 
    b = printf("2 %x\n", 1232); 
    printf("return : %d \n", a);
    printf("return : %d \n\n", b);


}