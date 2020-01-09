# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 11:20:25 by cpieri            #+#    #+#              #
#    Updated: 2020/01/09 13:06:49 by cpieri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ssl

CC		=	gcc

ERROR	=	-g3 -flto -fsanitize=address -fno-omit-frame-pointer

override CFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS=	-Iincludes

FLAGSFT	=	-L./libft -lft

SRC_PATH=	srcs

OBJ_PATH=	obj

DEPS =		Makefile						\
			includes/ft_ssl.h				\
			includes/define.h				\
			includes/enum.h					\
			includes/functions.h			\
			includes/structure.h			\
			includes/hash/sha256.h			\
			includes/hash/hash.h			\
			includes/hash/md5.h				\
			includes/hash/sha1.h			\
			includes/hash/hmac.h			\
			includes/base64/base64.h		\
			includes/pbkdf2/pbkdf.h		\
			includes/symmetric/symmetric.h	\
			includes/symmetric/des/des.h	\
			libft/libft.a

SRC_NAME= 	main.c									\
			parsing.c								\
			dispatch.c								\
			tools/clean.c							\
			tools/usage.c							\
			tools/error.c							\
			tools/get_data.c						\
			tools/get_data_1.c						\
			tools/open_fd.c							\
			tools/lst_opt.c							\
			hash/hash_parsing.c						\
			hash/display_hash.c						\
			hash/hash_tools.c						\
			hash/sha256/sha256.c					\
			hash/sha256/sha256_utils.c				\
			hash/md5/md5_utils.c					\
			hash/md5/md5.c							\
			hash/sha1/sha1.c						\
			hash/sha1/sha1_utils.c					\
			hash/hmac/hmac_utils.c					\
			hash/hmac/hmac_md5.c					\
			hash/hmac/hmac_sha1.c					\
			hash/hmac/hmac_sha256.c					\
			base64/base64.c							\
			base64/base64_encode.c					\
			base64/base64_decode.c					\
			base64/base64_parsing.c					\
			base64/base64_help_parsing.c			\
			base64/base64_display.c					\
			pbkdf2/pbkdf2.c							\
			pbkdf2/pbkdf2_utils.c					\
			symmetric/symmetric_usage.c				\
			symmetric/symmetric_parsing.c			\
			symmetric/symmetric_parsing_pt_f.c		\
			symmetric/symmetric_parsing_pt_f_2.c	\
			symmetric/des/des.c						\

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

.PHONY:	all clean fclean re echo

all:		LFT $(NAME)

$(NAME):	libft echo $(OBJ)
			@$(CC) $(CFLAGS) $(FLAGSFT) -o $(NAME) $(OBJ) $(CPPFLAGS)
			@echo "\n$(GREEN)$(NAME) ready!$(NONE)"

echo:
			@ echo -n Getting $(NAME) ready

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
			@mkdir $(dir $@) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
			@echo -n .

clean:
			@echo "$(YELLOW)Cleaning...$(NONE)"
			@make clean -C ./libft/
			@/bin/rm -f $(OBJ)
			@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean:		clean
			@make fclean -C ./libft/
			@echo "$(RED)Libft.a deleted$(NONE)"
			@/bin/rm -f $(NAME)
			@echo "$(RED)$(NAME) deleted !$(NONE)"

re:			fclean all

LFT:
		@make -C ./libft/;
		@echo "\n$(GREEN)Libft ready!$(NONE)";
