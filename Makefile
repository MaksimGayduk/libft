# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 17:24:42 by mgayduk           #+#    #+#              #
#    Updated: 2019/08/16 17:36:14 by maks             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		:= gcc -Wall -Wextra -Werror -c -g

NAME 	:= libft.a

INC_DIR := ./includes

SRC_DIRS := mem_funcs	str_funcs	str_arr_funcs	\
			char_funcs 	list_funcs 	int_funcs		\
			rw_funcs 	ft_printf 	btree_funcs		\
			ft_getopt

OBJ_DIR	:= ./objs
DEP_DIR	:= ./deps

# Source files
SEARCH_WILCARDS := $(addsuffix /*.c,$(SRC_DIRS))
SRC := $(notdir $(patsubst %.c,%.o,$(wildcard $(SEARCH_WILCARDS))))

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: prepare_dirs $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

VPATH := $(SRC_DIRS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $< -I$(INC_DIR) -MMD -MF $(DEP_DIR)/$(notdir $(patsubst %.o,%.d,$@)) -o $@

include $(wildcard $(DEP_DIR)/*.d)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
