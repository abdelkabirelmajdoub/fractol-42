CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRC = src/fractol.c src/events.c src/utils.c src/draw.c  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c src/fractol.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C fbonus

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@make all -C fbonus