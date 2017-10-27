# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 16:08:33 by lgaveria          #+#    #+#              #
#    Updated: 2017/10/27 19:18:21 by lgaveria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRCS = cleanup_functions.c \
	   lem_in.c \
	   line_recognition.c \
	   get_path.c \
	   coding_help.c \

LIBFT = Libft/libft.a

LIB = -L Libft/ -lft

PRINT = -L Printf_srcs/ -lft

SRC = $(addprefix srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	gcc $^ -o $@ $(CFLAGS) $(LIB) $(PRINT)

$(LIBFT):
	make -C Libft/

$(PRINTF):
	make -C Printf_srcs/

%.o: %.c
	gcc -c $^ -o $@ $(CFLAGS) -I include/

clean:
	make clean -C Libft/
	make clean -C Printf_srcs/
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft/
	make fclean -C Printf_srcs/
	rm -f $(NAME)

re: fclean all
