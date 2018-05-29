#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:33:09 by avallois          #+#    #+#              #
#    Updated: 2018/03/28 16:54:03 by avallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft/libft.a

SRCS = ft_printf.c flags_1.c flags_2.c converters_1.c converters_2.c \
	   converters_3.c converters_4.c converters_5.c octal_hexa.c \
	   precisions_and_int_to_char.c conversions_and_specifiers.c \
	   specifiers_checkers.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft all
	cp $(LIB) $(NAME)
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean :
	make -C libft clean
	rm -f $(OBJ)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
