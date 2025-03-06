NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = drawingstuff/drawlinetools.c \
	drawingstuff/drawlines.c \
	gnl/get_next_line_utils.c \
	gnl/get_next_line.c \
	hooksnloops/keyhooks.c \
	hooksnloops/mousehooks.c \
	init/fetchmap.c \
	init/getdata.c \
	mathutils/rotationsandiso.c \
	utils/frees.c \
	utils/ft_atoi_base.c \
	utils/ft_split.c \
	utils/ft_strjoin.c \
	utils/utilsutils.c \
	fdf.c \
	init/checkmap.c \
	drawingstuff/grading.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) fdf.h
	$(CC) $(CFLAGS) $(OBJ) -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re