CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIB = ar rc

NAME = libft.a
HEADER = libft.h

SRCS = $(wildcard *.c)	

OBJS = $(SRCS:.c=.o)

%.o:%.c 	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
