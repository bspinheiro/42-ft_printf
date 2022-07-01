# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 18:08:33 by bda-silv          #+#    #+#              #
#*   Updated: 2022/07/01 15:03:37 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -I $(LIB) -c $< -o $(<:.c=.o)

LIB		=	./libft

NAME	=	libftprintf.a

CC 		=	cc
CFLAGS 	=	-Wall -Wextra -Werror

RM		=	rm -f

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

x:			fclean
			$(RM) -r a.out a.out.dSYM

c:			all
			$(CC) $(FLAGS) $(SRCS) $(NAME)
			./a.out && $(MAKE) x

d:			all
			$(CC) $(FLAGS) -g $(SRCS) $(NAME)
			lldb a.out && $(MAKE) x

.PHONY:		all clean fclean re c d x
