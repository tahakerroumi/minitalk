# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 09:07:14 by tkerroum           #+#    #+#              #
#    Updated: 2024/04/25 16:31:11 by tkerroum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror 

EXEC_SERVER = server
EXEC_CLIENT = client
EXEC_SERVER_BONUS = server_bonus
EXEC_CLIENT_BONUS = client_bonus

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFT_INCLUDE = libft

all: $(LIBFT) $(EXEC_SERVER) $(EXEC_CLIENT)

$(EXEC_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -L$(LIBFT_PATH) -lft -o $(EXEC_SERVER)

$(EXEC_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -L$(LIBFT_PATH) -lft -o $(EXEC_CLIENT)

$(EXEC_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -L$(LIBFT_PATH) -lft -o $(EXEC_SERVER_BONUS)

$(EXEC_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -L$(LIBFT_PATH) -lft -o $(EXEC_CLIENT_BONUS)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE) -c $< -o $@

bonus: $(LIBFT) $(EXEC_CLIENT_BONUS) $(EXEC_SERVER_BONUS)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(LIBFT) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	rm -rf $(EXEC_CLIENT) $(EXEC_SERVER) $(LIBFT) $(EXEC_CLIENT_BONUS) $(EXEC_SERVER_BONUS)

re: fclean all
