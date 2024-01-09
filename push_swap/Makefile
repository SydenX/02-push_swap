# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:47:45 by jtollena          #+#    #+#              #
#    Updated: 2024/01/09 09:30:52 by jtollena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = srcs/main.c \
			srcs/instructions.c

OBJECTS = $(SOURCES:.c=.o)
INCLUDES = includes
FLAGS =  #-Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) -Ilibft -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	make -C libft/
	gcc $(OBJECTS) -Llibft -lft -o $(NAME)

clean:
	rm $(OBJECTS)
	make -C libft/ clean

fclean:
	rm $(OBJECTS)
	rm $(NAME)
	make -C libft/ fclean

re: fclean $(NAME)

.PHONY: re fclean clean all