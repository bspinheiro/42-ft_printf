# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 18:08:33 by bda-silv          #+#    #+#              #
#*   Updated: 2022/07/05 16:14:32 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS	=	f_arg_c.c \
			f_arg_di.c \
			f_arg_p.c \
			f_arg_pc.c \
			f_arg_s.c \
			f_arg_u.c \
			f_arg_x.c \
			ft_printf.c \

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
			$(MAKE) fclean -C $(LIB)
			$(RM) $(NAME)

re:			fclean all

bclean:		fclean
			$(RM) -r a.out a.out.dSYM

c:			all
			$(CC) $(FLAGS) $(SRCS) $(NAME)
			./a.out && $(MAKE) bclean

debug:		all
			$(CC) $(FLAGS) -g $(SRCS) $(NAME)
			lldb a.out && $(MAKE) bclean

.PHONY:		all clean fclean re c dbg bclean
