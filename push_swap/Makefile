# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:47:45 by jtollena          #+#    #+#              #
#    Updated: 2024/01/10 12:09:34 by jtollena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = srcs/main.c \
			srcs/instructions_s.c \
			srcs/instructions_p.c \
			srcs/instructions_r.c \
			srcs/instructions_rr.c \
			srcs/estimations.c \
			srcs/moves.c \
			srcs/moves_helper.c \
			srcs/sort.c \
			srcs/stack_infos.c \
			srcs/utils.c

OBJECTS = $(SOURCES:.c=.o)
INCLUDES = includes
FLAGS =  -Wall -Wextra -Werror

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