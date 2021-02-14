# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 17:57:32 by lmurray           #+#    #+#              #
#    Updated: 2021/02/14 20:37:40 by lmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR_HANDLER = processing/
SRC_DIR_PARSE = parsing/
LIB_DIR = libft/
SRC_FILES_HANDLER = handler_ch_str_ptr.c \
			handler_hex.c \
			handler_int_unsign.c \
			handler_width_accuracy_int.c \
			handler_width_ch_ptr_str.c \
			handler_width_utils.c \
			processing.c \
			handler_minus.c \
			handler_wa_str.c \
			handler_percent.c \
			handler_ch_str_ptr_utils.c

SRC_FILES_PARSE = parser.c \
			parse_spec_flags_utils.c \
			parse_spec_types.c \
			parse_spec_types_utils.c \
			parse_spec_types_utils2.c \
			parse_specificators.c \

LIBFT_FILES = ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_itoa_unsign.c \
				ft_memcmp.c \
				ft_nbrlen.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_substr.c

SRC_HANDLER = $(addprefix $(SRC_DIR_HANDLER), $(SRC_FILES_HANDLER))
SRC_PARSE = $(addprefix $(SRC_DIR_PARSE), $(SRC_FILES_PARSE))
LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))

OBJ = $(SRC_FILES_HANDLER:.c=.o) $(LIBFT_FILES:.c=.o) $(SRC_FILES_PARSE:.c=.o)

INC = -I headers/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC_PARSE) $(SRC_HANDLER) ft_printf/ft_printf.c $(LIBFT) $(INC)
	@ar rcs $(NAME) $(OBJ) ft_printf.o
	@echo "(￣ヘ￣)"

clean:
	@/bin/rm -f $(OBJ) ft_printf.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
