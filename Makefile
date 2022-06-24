NAME		= libftprintf.a

SRCS					= ft_printf.c \
						ft_specifier_di.c \
						ft_tag.c \
						ft_di_util.c \
						ft_number_util.c \
						ft_specifier_u.c \
						ft_specifier_persent.c \
						ft_print_c.c

BNS_SRCS				= \

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all	:	$(NAME)

HEADERS = includes/ft_printf.h

$(NAME) : $(OBJ_FILES)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o	: %.c
	gcc $(FLAGS) -c $^  -o $@


bonus :
	make WITH_BONUS=1 all

clean	:
		rm -f $(OBJS) $(BNS_OBJS)
 
fclean	:	clean
		rm -f $(NAME)


re	:	fclean all

.PHONY	:	all clean fclean re bonus