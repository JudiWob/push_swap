# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 15:04:29 by jpaselt           #+#    #+#              #
#    Updated: 2025/02/20 21:20:24 by jpaselt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

SOURCES		= 	ft_atoi.c


BONUS_OBJS	= $(BONUS:.c=.o)

OBJS		= $(SOURCES:.c=.o)

HEADER		= libft.h

RM			= rm -f

all:		${NAME}

$(NAME):  $(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
			${RM} ${OBJS} $(BONUS_OBJS)
			
bonus:		all

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

