CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRC =  fractol.c events.c utils.c draw.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C minilibx
	$(CC) $(CFLAGS)  $(OBJ) -L./minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	@make clean -C minilibx
	rm -f $(NAME)

re: fclean all