# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrass <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 21:45:31 by mgrass            #+#    #+#              #
#    Updated: 2019/09/04 13:31:58 by mgrass           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

C_FILE = ft_display_file.c

HEADER = ft_list.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) $(C_FILE) -I $(HEADER)

clean:
	/bin/rm -f *.o

fclean:
	/bin/rm -f $(NAME)

re: fclean all
