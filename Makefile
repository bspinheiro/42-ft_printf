# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 18:08:33 by bda-silv          #+#    #+#              #
#*   Updated: 2022/06/23 14:22:02 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -I $(LIB) -c $< -o $(<:.c=.o)

LIB		=	./libft

NAME	=	libftprint.a

CC 		=	@cc
CFLAGS 	=	-Wall -Wextra -Werror

RM		=	@rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIB) && cp $(LIB)/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(MAKE) clean -C $(LIB)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

c:			all
			$(CC) $(FLAGS) $(SRCS) $(NAME)
			./a.out && rm a.out && $(MAKE) clean

.PHONY:		all clean fclean re c
