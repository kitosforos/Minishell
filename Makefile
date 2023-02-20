NAME = minishell
LEAKS = -fsanitize=address -static-libasan -g
LIBFT = libft/libft.a
SRCS = src/builtins.c src/process.c src/minishell.c src/main.c src/env.c src/builtins2.c src/redir.c src/signals.c src/ft_split2.c src/quotes.c src/free.c
INC = -IUsers/${USER}/.brew/opt/readline/include -Iinc -Ilibft
LIB = -L/Users/${USER}/.brew/opt/readline/lib -lreadline 
OBJS = $(patsubst src/%, obj/%, $(SRCS:.c=.o))
CFLAGS = -Wall -Wextra -Werror
############################
$(NAME): $(OBJS) $(LIBFT)
		gcc $(CFLAGS) -g $^ -o $@ -Llibft -lft $(INC) $(LIB)

$(LIBFT):
		make bonus -C libft

all: $(NAME)

obj/%.o: src/%.c
		gcc $(CFLAGS) -c -g $< -o $@ $(INC)

clean:
		rm $(OBJS)

fclean: clean
		rm $(NAME)
		make fclean -C libft

re: fclean $(NAME)
