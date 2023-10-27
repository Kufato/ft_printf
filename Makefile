# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 10:02:59 by axcallet          #+#    #+#              #
#    Updated: 2022/10/24 09:29:16 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf.c \
			ft_utils.c \
			ft_putnbr.c

CFLAGS =	-Wall -Werror -Wextra

OBJS =		$(SRCS:.c=.o)

.c.o :
			gcc -g $(CFLAGS) -c $(SRCS)

RM =		rm -f

$(NAME) :	$(OBJS)
				ar -rcs $(NAME) $(OBJS)

all :		$(NAME)

clean :
			$(RM) $(OBJS)

fclean :	clean
				$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
