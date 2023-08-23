# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:42:05 by tburlacu          #+#    #+#              #
#    Updated: 2023/08/23 02:43:49 by tburlacu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
PRINTF = printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

all: $(SERVER_NAME) $(CLIENT_NAME) $(PRINTF)

$(SERVER_NAME) $(CLIENT_NAME):
	@$(CC) $(CFLAGS) -g $@.c -o $@ ft_printf.c

$(PRINTF):
	@$(CC) $(CFLAGS) -g ft_printf.c -o $@

clean:
	@rm -f $(SERVER_NAME)
	@rm -f $(CLIENT_NAME)
	@rm -f $(PRINTF)

fclean: clean
	@rm -f $(PRINTF)

re: fclean all

