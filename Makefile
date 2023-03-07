NAME = so_long
#BONUS = bonus
UNAME_S := $(shell uname -s)
CC = cc
FLAGS = -g -Wall -Werror -Wextra
RED		:= \033[31;1m
RESET	:= \033[0m

OBJ = obj/main.o \
			
MLX = lib/MLX42/libmlx42.a
MLX_DIR = lib/MLX42/
LIBFT = obj/libft/libft.o
LIBFT_DIR = src/libft
NAME_H = include/so_long.h

ifeq ($(UNAME_S),Linux)
MLX_FLAGS = -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
MLX_FLAGS = -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(NAME_H) $(MLX)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

$(MLX): $(MLX_DIR)
	@make -C $(MLX_DIR)

clean:
	@echo "Cleaning object files.."
	@$(RM) $(OBJ) $(LIBFT) $(MLX) 

fclean: clean
	@echo "$(RED)Cleaning$(RESET)"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⡛⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢷⣄⣸⡇⠈⠉⠙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⢀⣀⣠⣤⣴⠶⠛⠋⠉⢿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠾⠟⠛⠛⠋⠉⠀⠀⣀⣀⣤⣴⠾⢿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣤⣤⣴⠶⠶⠟⠛⠋⠉⠁⠀⠀⠈⢿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡙⠻⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⢰⠀⠀⠀⠀⢀⠀⠀⡀⠀⢀⡀⠀⣄⢀⣤⣾⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⢀⣿⢠⡆⠀⢀⣼⣇⣀⣿⣦⣼⣿⣾⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re 