# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 10:30:53 by molapoug          #+#    #+#              #
#    Updated: 2025/05/27 22:18:13 by molapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g3

LIBFT = libft/
FT_PRINTF = ft_printf

AR = ar rcs
RM = rm -f

SRC = push_swap.c ft_divide_stack.c \
     ft_rotate_a_b.c ft_swap_a_b.c \
     ft_reverse_rotate.c utils.c \
     ft_sort_small.c  
OBJ = $(SRC:.c=.o)

LIBS = $(LIBFT)libft.a $(FT_PRINTF)libftprintf.a

# Color
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "$(YELLOW)😎🤙Linking executable$(PURPLE) $(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME)

%.o: %.c push_swap.h
	@echo "$(CYAN)🔥Compiling$(GREEN) $<$(NC)"
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT)libft.a:
	@make -C $(LIBFT)

$(FT_PRINTF)libftprintf.a:
	@make -C $(FT_PRINTF)

clean:
	@echo "$(CYAN)🧹Cleaning object files$(NC)"
	@$(RM) $(OBJ)
	@make -C $(LIBFT) clean
	@make -C $(FT_PRINTF) clean

fclean: clean
	@echo "$(CYAN)🚮Cleaning$(RED) $(NAME)$(NC)"
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(FT_PRINTF) fclean

re: fclean all

bonus:
	@echo "$(PURPLE)💡Bonus not implemented yet$(NC)"

.PHONY: all clean fclean re bonus
