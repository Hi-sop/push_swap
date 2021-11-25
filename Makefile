CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= main.c \
	  find_pivot.c \
	  functional1.c \
	  functional2.c \
	  functional3.c \
	  functional4.c \
	  simplecase1.c \
	  simplecase2.c \
	  solve.c \
	  utils1.c \
	  utils2.c \

OBJS= $(SRCS:.c=.o) 

NAME= push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(MLX) -o $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
