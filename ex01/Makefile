# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amejia <amejia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 17:23:35 by amejia            #+#    #+#              #
#    Updated: 2023/06/26 18:44:03 by amejia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

NAME = trap
NAME_DEBUG = debug


OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(NAME_DEBUG): $(SRCS) 
	$(CC) $(CFLAGS) $(SRCS) -o $@

debug: $(NAME_DEBUG)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME_DEBUG)

re: fclean all

.PHONY = all clean fclean debug re debug