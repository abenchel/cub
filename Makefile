NAME = cub3d

HDER = cub3d.h
SRC = tst.c




CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
AR = ar rcs

OBJ = $(SRC:.c=.o)
MLX = "./MLX42/build/libmlx42.a"
# linux 
# LDFLAGS = -Iinclude -ldl -lglfw -pthread -lm
#MAC
# LDFLAGS = -O3 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LDFLAGS = -O3 -Iinclude `pkg-config --cflags --libs glfw3`
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(OBJ) $(HDER)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all