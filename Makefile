# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 20:15:08 by rphuyal           #+#    #+#              #
#    Updated: 2023/07/25 22:43:40 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
CBOLD   = \033[0;1m
RED     = \033[0;41m
GREEN   = \033[0;42m
BLUE   = \033[0;44m
YELLOW  = \033[0;43m
RESET   = \033[0m

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = src/server.c src/client.c
# Use obj/ as the prefix for object file names
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

# Add a dependency on the obj target to ensure that the obj directory exists
# before any object files are created
all: obj server client
	@echo "$(CBOLD)$(GREEN)    SERVER READY!   $(RESET)"
	@echo "$(CBOLD)$(GREEN)    CLIENT READY!   $(RESET)"

# Same as all
bonus: obj server client

server: obj/server.o libft
	@$(CC) -o $@ $< -Llibft -lft

client: obj/client.o libft
	@$(CC) -o $@ $< -Llibft -lft

# Create object files in obj/ directory
obj/%.o: src/%.c | obj
	@$(CC) -c $(FLAGS) $< -o $@

# Create obj directory if it doesn't exist
obj:
	@mkdir -p obj

libft:
	@echo "$(CBOLD)$(YELLOW)  Compiling Libft   $(RESET)"
	@make -sC ./libft
	@echo "$(CBOLD)$(GREEN)    Libft ready!    $(RESET)\n ↪"

clean:
	@make -sC libft clean
	@rm -rf $(OBJ) obj
	@echo "$(CBOLD)$(BLUE)  Objects removed!  $(RESET)"

fclean: clean
	@make -sC libft fclean
	@rm -rf obj server client libft/libft.a
	@echo "$(CBOLD)$(BLUE)  Binaries removed! $(RESET)"

re: fclean all

# Add obj target to list of phony targets
.PHONY: all bonus libft clean fclean re obj
