# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:53:09 by jkaczmar          #+#    #+#              #
#    Updated: 2021/12/06 23:20:37 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = libftprintf.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = 			ft_printf.c\
				ft_putchar.c\
				ft_putstr_fd.c\
				typecheck.c\
				ft_putnbr_fd.c\
				ft_strlen.c\
				ft_puttinghex.c\
				ft_printstuff.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	@rm -f $(OBJS) $(TOBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) $(TNAME)

re: fclean all

.PHONY: all clean fclean re
