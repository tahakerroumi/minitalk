# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 00:21:14 by tkerroum          #+#    #+#              #
#    Updated: 2024/04/22 06:10:33 by tkerroum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SRC = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_strrchr.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_isascii.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putchar.c\
	ft_printp.c\
	ft_putstr.c\
	ft_printf.c\
	ft_printhex.c\
	ft_putnbr.c\
	ft_printu.c\

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rc $(NAME) $@
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
