all: 
	gcc -lft -Llibft builtins.c main.c -lreadline -L /Users/$USER/.brew/opt/readline/lib -I /Users/$USER/.brew/opt/readline/include