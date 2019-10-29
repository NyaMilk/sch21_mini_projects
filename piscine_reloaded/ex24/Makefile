# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrass <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 20:49:17 by mgrass            #+#    #+#              #
#    Updated: 2019/09/03 20:58:30 by mgrass           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OUT = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

INCLUDES = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OUT)

fclean: 
	/bin/rm -f $(NAME)

re: fclean all
