NAME=cub3d

all:
	gcc -I includes/  libft/*.c src/*.c main.c -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
run :
	rm -rf ./maps/cpmap.cub && gcc -I includes/  libft/*.c src/*.c main.c -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./cub3d maps/minimalist.cub

linux :
	gcc -I includes/  libft/*.c src/*.c main.c -lm -Lmlx -lmlx ./mlx/libmlx.a -o $(NAME) && ./cub3d maps/minimalist.cub
