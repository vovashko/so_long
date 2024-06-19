NAME 		= libftprintf.a

SRCS 		= ft_char.c ft_words.c ft_hex.c ft_numbers.c \
				ft_pointer.c ft_unsigned.c ft_printf.c

OBJS 		= $(SRCS:.c=.o)



CC 			= cc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re