NAME = cub3d
FLAGS = -Wall 
MLX = "./MLX42/build/libmlx42.a"
# linux 
# LDFLAGS = -Iinclude -ldl -lglfw -pthread -lm
#MAC
FILES = tst..c
LDFLAGS = -O3 -Iinclude -lglfw -L"/opt/homebrew/opt/glfw/lib"
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
all: $(NAME)
$(NAME): $(FILES)
	gcc  $(FILES) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all