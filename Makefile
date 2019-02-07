# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 11:20:25 by cpieri            #+#    #+#              #
#    Updated: 2019/02/07 19:27:49 by cpieri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	ft_ssl

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -O3 -flto -g -fsanitize=address -fno-omit-frame-pointer

CPPFLAGS=	-Iincludes

FLAGSFT	=	-L./libft -lft

SRC_PATH=	srcs

OBJ_PATH=	obj

DEPS =		Makefile				\
			includes/ft_ssl_md5.h	\
			libft/libft.a

SRC_NAME= 	main.c		\
			usage.c		\
			parsing.c	\
			md5.c


OBJ_NAME=	$(SRC_NAME:.c=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

NONE = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m

.PHONY:	all clean fclean re echo norm

all:		LFT $(NAME)

$(NAME):	libft echo $(OBJ)
			@$(CC) $(CFLAGS) $(FLAGSFT) -o $(NAME) $(OBJ) $(CPPFLAGS)
			@echo "\n$(GREEN)$(NAME) ready!$(NONE)"

echo:
			@ echo -n Getting $(NAME) ready

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
			@echo -n .

clean:
			@echo "$(YELLOW)Cleaning...$(NONE)"
			@make clean -C ./libft/
			@/bin/rm -f $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true
			@/bin/rm -rf $(PATH_SDL)

fclean:		clean
			@make fclean -C ./libft/
			@echo "$(RED)Libft.a deleted$(NONE)"
			@/bin/rm -f $(NAME)
			@echo "$(RED)$(NAME) deleted !$(NONE)"

norm:		clean
			@echo "$(CYAN)Running norminette...$(NONE)"
			@norminette $(SRC_PATH) $(INCLUDE) libft/ libgraph/ \
				| grep -B 1 '^Error' 2> /dev/null || echo '$(GREEN)Norme OK !$(NONE)';

re:			fclean all

LFT:
		@make -C ./libft/;
		@echo "\n$(GREEN)Libft ready!$(NONE)";
