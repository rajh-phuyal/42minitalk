# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 20:15:08 by rphuyal           #+#    #+#              #
#    Updated: 2023/04/23 20:15:09 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = src/server.c src/client.c
# Use obj/ as the prefix for object file names
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

# Add a dependency on the obj target to ensure that the obj directory exists
# before any object files are created
all: obj server client

# Same as all
bonus: obj server client

server: obj/server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: obj/client.o libft
	$(CC) -o $@ $< -Llibft -lft

# Create object files in obj/ directory
obj/%.o: src/%.c | obj
	$(CC) -c $(FLAGS) $< -o $@

# Create obj directory if it doesn't exist
obj:
	mkdir -p obj

libft:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf obj server client libft/libft.a

re: fclean all

# Add obj target to list of phony targets
.PHONY: all bonus libft clean fclean re obj
