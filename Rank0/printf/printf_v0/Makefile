# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 12:11:26 by ppenuela          #+#    #+#              #
#    Updated: 2024/07/19 19:08:05 by ppenuela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
CPPFLAGS	= -I include
RM		= rm -rf
NAME	= libftprintf.a
AR		= ar rc
OBJS	= $(SRCS:%.c=%.o)
SRCS	= ft_formatprintft.c\
ft_printf.c\
ft_putchar.c\
ft_putstr.c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re