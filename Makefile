# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 16:08:33 by lgaveria          #+#    #+#              #
#    Updated: 2017/10/23 19:24:03 by lgaveria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRCS = cleanup_functions.c \
	   lem_in.c \
	   line_recognition.c \
	   coding_help.c \

LIBFT = Libft/libft.a

LIB = -L Libft/ -lft

SRC = $(addprefix srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $^ -o $@ $(CFLAGS) $(LIB)

$(LIBFT):
	make -C Libft/

%.o: %.c
	gcc -c $^ -o $@ $(CFLAGS) -I include/

clean:
	make clean -C Libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft/
	rm -f $(NAME)

re: fclean all
