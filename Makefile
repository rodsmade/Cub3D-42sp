NAME	= cub3D

CC				=	gcc
CFLAGS			=	-g -Wall -Werror -Wextra
RM				=	rm -f
VALGRIND		=	valgrind --leak-check=full --show-leak-kinds=all \
						--track-origins=yes -q --tool=memcheck
INCLUDES_DIR	=	./includes ./libs/libft ./libs/minilibx-linux
SRC_DIR			=	./src
OBJ_DIR			=	./obj

MLIBX_PATH		=	./libs/minilibx-linux
MLIBX			=	$(MLIBX_PATH)/libmlx.a
MLX_FLAGS		=	-L$(MLIBX_PATH) -lmlx -lXext -lX11
LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a
LIBFT_FLAGS 	=	-L$(LIBFT_PATH) -lft
INCLUDES		=	$(addprefix -I,$(INCLUDES_DIR))

SRCS			=	cub3D.c \

OBJS			:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS			:=	$(addprefix $(SRC_DIR)/,$(SRCS))

all:	$(NAME)

$(NAME): $(LIBFT) $(MLIBX_PATH) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(MLIBX_PATH):
	make -C $(MLIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS) $(MLX_FLAGS)

clean:
	# make -C clean $(MLIBX_PATH)
	make clean -C $(LIBFT_PATH)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	# make clean $(MLIBX_PATH)
	$(RM) $(NAME)

re:	fclean all

run: all
	clear
	./$(NAME) $$MAP

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $$MAP

.PHONY:	all clean fclean re go valgrind
