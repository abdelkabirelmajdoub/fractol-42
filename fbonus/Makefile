CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ../fractol
SRC =  fractol_bonus.c events_bonus.c utils_bonus.c draw_bonus.c burningship_bonus.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ)
