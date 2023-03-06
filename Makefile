NAME = minishell
LEAKS = -fsanitize=address -g3
LIBFT = libft/libft.a
SRCS = src/builtins.c src/process.c src/minishell.c src/main.c src/env.c src/env2.c \
		src/builtins2.c src/builtins3.c src/redir.c src/signals.c src/ft_split2.c src/quotes.c src/quotes2.c src/quotes3.c \
		 src/quotes4.c src/free.c src/redir2.c src/redir3.c src/process2.c src/ft_split22.c src/minishell2.c
INC = -IUsers/${USER}/.brew/opt/readline/include -Iinc -Ilibft
LIB = -L/Users/${USER}/.brew/opt/readline/lib -lreadline 
OBJS = $(patsubst src/%, obj/%, $(SRCS:.c=.o))
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
############################
$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS)  -g $^ -o $@ -Llibft -lft $(INC) $(LIB)

$(LIBFT):
		make bonus -C libft

all: $(NAME)

obj/%.o: src/%.c
		$(CC) $(CFLAGS) -c -g $< -o $@ $(INC)

clean:
		rm -f obj/*.o

fclean: clean
		rm -f $(NAME)
		make fclean -C libft

re: fclean $(NAME)
