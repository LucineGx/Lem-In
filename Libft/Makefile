# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 18:32:45 by lgaveria          #+#    #+#              #
#    Updated: 2017/10/23 19:30:03 by lgaveria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_strcat.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strjoinfree.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strsplit.c \
	   ft_strsub.c \
	   ft_strsplit.c \
	   charactere_recognition.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -c $^ -o $@ $(CFLAGS)

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
