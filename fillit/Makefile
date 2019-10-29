.PHONY: all clean fclean re

NAME = fillit

LIBFT = libft

SRCS = main.c valid.c makelist.c solve.c extra.c

OBJS = $(SRCS:%.c=%.o)

INCLUDES = libft/includes

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
