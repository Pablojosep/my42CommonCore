# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 12:11:26 by ppenuela          #+#    #+#              #
#    Updated: 2024/05/01 15:36:26 by ppenuela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
CPPFLAGS	= -I include
RM		= rm -rf
NAME	= libft.a
AR		= ar rc
OBJS	= $(SRCS:%.c=%.o)
SRCS	= ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_strchr.c\
ft_strcmp.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strrchr.c\
ft_tolower.c\
ft_toupper.c\
ft_bzero.c\
ft_atoi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strdup.c\
ft_memcmp.c\
ft_memchr.c\
ft_calloc.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_itoa.c\
ft_strmapi.c\
ft_striteri.c\
ft_split.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c

BOBJS	= $(BSRCS:%.c=%.o)
BSRCS	= ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
bonus: $(OBJS) $(BOBJS)
	$(AR) $(NAME) $(OBJS) $(BOBJS)

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