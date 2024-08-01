
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

RM =		rm -f

LIB =		ar rc

NAME =		libftprintf.a
HEADER =	ft_printf.h

SRCS =		ft_printf.c \
			ft_putchar_n.c ft_putstr.c \
			ft_putnbr_n.c ft_put_uint_nbr.c \
			ft_put_ptr.c \
			ft_puthexa_nbr.c \

OBJS =		$(SRCS:.c=.o)

%.o:%.c		$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
