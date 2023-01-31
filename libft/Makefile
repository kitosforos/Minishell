# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 11:05:52 by rchallie          #+#    #+#              #
#    Updated: 2022/04/03 21:12:05 by dcruz-na         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_atoi.c		\
		ft_striteri.c     \
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c		\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

SRCSB =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		$(SRCS)

NAME = libft.a 

S_NAME = .simple

B_NAME = .bonus

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(S_NAME)

$(S_NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	rm -f $(B_NAME)
	touch $(S_NAME)
	@echo "Libft ready !"

all: $(NAME)

clean:
	rm -rf $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(B_NAME)
	
$(B_NAME): $(OBJSB)
	ar rcs $(NAME) $(OBJSB)
	rm -f $(S_NAME)
	touch $(B_NAME)
	@echo "Libft Bonus ready !"

