NAME = libft.a

SRCS = $(wildcard *_*.c)
INCLUDE = -I ./libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
