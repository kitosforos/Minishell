INC = -I/home/linuxbrew/.linuxbrew/opt/readline/include -Ilibft
CFLAGS = -Wall -Wextra -Werror
LIB = -L/home/linuxbrew/.linuxbrew/opt/readline/lib -lreadline -Llibft -lft
LIBFT = libft.a

all: $(LIBFT)
	gcc $(CFLAGS) main.c process.c minishell.c builtins.c -o minishell $(INC) $(LIB)

$(LIBFT):
	make -C libft
