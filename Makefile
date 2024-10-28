# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:25:55 by agiliber          #+#    #+#              #
#    Updated: 2024/08/27 13:54:54 by agiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# 								HEADER
# ------------------------------------------------------------------------------

NAME_LIB = my_libft.a
NAME = so_long
HEADER = so_long.h

# ------------------------------------------------------------------------------
# 								COMPILATION
# ------------------------------------------------------------------------------

CC = cc
CFLAGS = -Wall -Wextra -Werror -I -g3
LIBFT_FLAGS = -L./$(LIB_DIR) -l:my_libft.a
EXE_FLAGS = -lX11 -lXext

# ------------------------------------------------------------------------------
# 									DIR
# ------------------------------------------------------------------------------

LIB_DIR = My_Libft/
SRC_DIR = src/
OBJ_DIR = obj/
MINILIBX = ./mlx-linux
MINILIBX_FLAGS = -L./$(MINILIBX) -l:libmlx_Linux.a

# ------------------------------------------------------------------------------
# 									FILES
# ------------------------------------------------------------------------------

SRC = map_check.c map_dimensions.c map_rules.c map_rules2.c so_long.c \
	fill_struct.c game_init.c error_handler.c action_handling.c \
	map_update.c close_window.c flood_fill.c free_final.c

SRCF = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
DEP = $(OBJ:%.o=%.d)

LIBFT_OBJ = $(addprefix $(LIB_DIR), $(NAME_LIB))

# ------------------------------------------------------------------------------
# 									COMMANDS
# ------------------------------------------------------------------------------

all : $(NAME)

$(NAME) : $(OBJ) | $(LIBFT_OBJ) $(MINILIBX)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MINILIBX_FLAGS) $(EXE_FLAGS) -o $@
	@echo "LIBFT COMPILED"

$(MINILIBX)/libmlx_Linux.a :
	make -C $(MINILIBX)

$(LIBFT_OBJ) :
	make -C $(LIB_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)
	make clean -C $(MINILIBX)
	@echo "Cleaned"

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re : fclean all

.PHONY : all clean fclean re

-include $(DEP)
