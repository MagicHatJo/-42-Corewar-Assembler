# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 20:46:21 by jochang           #+#    #+#              #
#    Updated: 2019/09/21 20:46:22 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC =	main \
		valid_extension \
		assembler \
		get_header \

INC =	-I inc \
		-I ../libft/inc \

LIB =	-L ../libft -lft \

VPATH = src

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

DEP = $(OBJ:%.o=%.d)

#CC = gcc
CC = clang-6.0
CFLAGS = -Wall -Wextra -Werror $(INC)
LDFLAGS = $(LIB)
MAKEOPTS = -j4

.PHONY: all
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@printf "\033[32mCreating: \033[0m%s\n" $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)

-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	@printf "\033[32mCompiling: \033[0m%s\n" $<
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@make -C ../libft
	@mkdir -p $(BIN_DIR)
	@printf "\033[32mLinking: \033[0m%s\n" $(NAME)
	@$(CC) $^ $(LDFLAGS) -o $(BIN_DIR)/$@

.PHONY: clean
clean:
	@make -C ../libft clean
	@printf "\033[33mCleaning: \033[0m%s repository\n" $(NAME)

.PHONY: fclean
fclean: clean
	@make -C ../libft fclean
	@printf "\033[33mCleaning: \033[0m%s\n" $(BIN_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME).dSYM

.PHONY: re
re: fclean all