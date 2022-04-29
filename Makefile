# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hejang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 01:34:29 by hejang            #+#    #+#              #
#    Updated: 2022/04/30 01:07:31 by hejang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS	=	list.c \
			parsing_arg.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			sorting_ba.c \
			sorting_ab.c \
			swap.c \
			two_three_elements.c \
			four_five_elements.c\
			main.c

OBJS	= $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
		$(MAKE) -C libft
		$(CC) $(CFLAG) $(OBJS) -Llibft	-lft -o $(NAME)	


clean : 
		$(MAKE) -C libft clean
		$(RM) $(RMFLAG) $(OBJS)

fclean : clean
		$(MAKE) -C libft fclean
		$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re
