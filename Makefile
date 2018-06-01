# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 14:40:12 by apyltsov          #+#    #+#              #
#    Updated: 2018/04/17 14:40:24 by apyltsov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	apyltsov.filler
BONUS	=	bonus
SFILES	=	read.c\
			get_next_line.c\
			new_algor.c
FILES	=	get_next_line.c\
			vizualize.c
BINS	=	$(SFILES:.c=.o) $(FILES:.c=.o)
LIBFT	=	libft/
LIBSRC	=	-lft -L libft/


all: $(NAME)

$(NAME): $(BINS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(SFILES:.c=.o) $(LIBSRC)
	@$(CC) $(CFLAGS) -lncurses -o $(BONUS) $(FILES:.c=.o) $(LIBSRC)

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

clean:
	@make clean -C $(LIBFT)
	@rm -f $(BINS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME) $(BONUS)

re: fclean all
