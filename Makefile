# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:11:08 by amedioun          #+#    #+#              #
#    Updated: 2023/05/15 13:50:12 by amedioun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ft_printf

CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
LIBFT_SRC = $(LIBFT_DIR)/libftprintf.a

CLIENT_OBJ = $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ = $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADER = minitalk.h

CLIENT_EXEC = client
SERVER_EXEC = server

all: $(CLIENT_EXEC) $(SERVER_EXEC)

$(shell mkdir -p $(OBJ_DIR))

$(OBJ_DIR)/client.o: $(CLIENT_SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/server.o: $(SERVER_SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $^ -L./$(LIBFT_DIR) -lftprintf -o $@

$(SERVER_EXEC): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $^ -L./$(LIBFT_DIR) -lftprintf -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC)

re: fclean all

.PHONY: all clean fclean re
