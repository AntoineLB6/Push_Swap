# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:55:17 by aleite-b          #+#    #+#              #
#    Updated: 2023/12/14 09:54:50 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

MAIN = push_swap_src/main.c

BONUS_MAIN = checker_src/main.c

SOURCES = push_swap_src/index.c \
			push_swap_src/rotate.c \
			push_swap_src/rotate_do.c \
			push_swap_src/sort.c \
			utils/args.c \
			utils/instructions.c \
			utils/instructions2.c \
			utils/instructions3.c \
			utils/is_sorted.c \
			utils/lst.c \
			utils/lst2.c \
			utils/utils.c \

			
OBJECTS = $(SOURCES:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(MAIN)

bonus: $(OBJECTS)
	$(CC) $(FLAGS) -o $(BONUS_NAME) $(OBJECTS) $(BONUS_MAIN)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)


.PHONY: all clean fclean re bonus
