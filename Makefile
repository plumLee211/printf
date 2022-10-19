# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoulee <jiyoulee@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 16:11:16 by jiyoulee          #+#    #+#              #
#    Updated: 2021/09/20 22:22:46 by jiyoulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

LIBFT	=	libft/libft.a

SRCS	= 	ft_printf.c ft_parse.c ft_char.c ft_nbr.c ft_hex.c \

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) compiler
			ar -rcs $(NAME) $(OBJS)

$(OBJS)	:	$(SRCS)
			$(CC) $(CFLAGS) -c $^

bonus	:	all

compiler:
		make all -C libft
		@cp $(LIBFT) $(NAME)

clean	:
	rm -f $(OBJS)
	@make clean -C libft

fclean	:	clean
	rm -f $(NAME)
	@make fclean -C libft

re		:	fclean all

.PHONY	:	all clean fclean re bonus
