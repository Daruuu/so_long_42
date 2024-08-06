HEADER=	get_next_line.h

HEADER_BONUS=	get_next_line.h

NAME=	get_next_line.a

SRCS=	get_next_line.c get_next_line_utils.c

OBJS= 	$(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

%.o : %.c get_next_line.h
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS} ${HEADER}
	$(AR) $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
