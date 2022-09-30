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

WINDOW_PATH		= window/
DESTROY_PATH	= destroy/
KEYSTROKES_PATH = keystrokes/

SRCS			=	cub3D.c							\
					error_handling.c				\
					free_memory.c					\
					init_data.c						\
					input_validation_utils.c		\
					input_validation.c				\
					map_params_checks.c				\
					map_validation.c				\
					params_utils.c					\
					$(WINDOW_PATH)window.c			\
					$(DESTROY_PATH)destroy.c		\
					$(KEYSTROKES_PATH)keystrokes.c	\

OBJS			:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS			:=	$(addprefix $(SRC_DIR)/,$(SRCS))

all:	$(NAME)

$(NAME): $(LIBFT) $(MLIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(MLIBX):
	make -C $(MLIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(WINDOW_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(DESTROY_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(KEYSTROKES_PATH))
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
