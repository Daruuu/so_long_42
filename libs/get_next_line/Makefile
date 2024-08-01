HEADER=	get_next_line.h

HEADER_BONUS=	get_next_line.h

NAME=	get_next_line.a

SRCS=	get_next_line.c get_next_line_utils.c \

SRCS_BONUS=	get_next_line_bonus.c get_next_line_utils_bonus.c \

OBJS= 	$(SRCS:.c=.o)
OBJS_BONUS= 	$(SRCS_BONUS:.c=.o)

CC= 		gcc
RM= 		rm -f
AR= 		ar -rcs
CFLAGS=		-Wall -Wextra -Werror

all: $(NAME)

%.o : %.c get_next_line.h
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS} ${HEADER}
	$(AR) $(NAME) $(OBJS)

bonus: get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h
		$(CC) $(CFLAGS) -c get_next_line_bonus.c -o get_next_line_bonus.o
		$(CC) $(CFLAGS) -c get_next_line_utils_bonus.c -o get_next_line_utils_bonus.o
		$(AR) $(NAME) get_next_line_bonus.o get_next_line_utils_bonus.o

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
