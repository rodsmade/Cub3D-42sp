# VARIABLES
## binary
NAME	= cub3D

## compilation
CC				=	gcc
CFLAGS			=	-g -Wall -Werror -Wextra
INCLUDES		=	$(addprefix -I,$(INCLUDES_DIR))

## bash commands
RM				=	rm -f

## valgrind
VALGRIND		=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

## directories
INCLUDES_DIR			=	./includes ./libs/libft ./libs/minilibx-linux
SRC_DIR					=	./src
OBJ_DIR					=	./obj
DESTROY_PATH			=	destroy/
KEYSTROKES_PATH			=	keystrokes/
INPUT_VALIDATION_PATH	=	input_validation/
UTILS_PATH				=	utils/
WINDOW_PATH				=	window/
RAYCASTING_PATH			=	ray_casting/

## libs
MLIBX_PATH		=	./libs/minilibx-linux
MLIBX			=	$(MLIBX_PATH)/libmlx.a
MLX_FLAGS		=	-L$(MLIBX_PATH) -lmlx -lXext -lX11

LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a
LIBFT_FLAGS		=	-L$(LIBFT_PATH) -lft

LIBMATH_FLAGS	=	-lm

## source files
SRCS			=	cub3D.c									\
					error_handling.c						\
					hooks.c								\
					init_data.c								\
					memory_release.c						\
					texture_loading.c						\
					$(DESTROY_PATH)destroy.c				\
					$(INPUT_VALIDATION_PATH)input_validation_utils.c			\
					$(INPUT_VALIDATION_PATH)input_validation.c					\
					$(INPUT_VALIDATION_PATH)map_padding.c						\
					$(INPUT_VALIDATION_PATH)map_params_checks.c					\
					$(INPUT_VALIDATION_PATH)map_utils.c							\
					$(INPUT_VALIDATION_PATH)map_validation.c					\
					$(INPUT_VALIDATION_PATH)map_validation_player_position.c	\
					$(INPUT_VALIDATION_PATH)map_validation_utils.c				\
					$(KEYSTROKES_PATH)keystrokes.c			\
					$(KEYSTROKES_PATH)rotate.c				\
					$(KEYSTROKES_PATH)move_player.c			\
					$(RAYCASTING_PATH)dda.c					\
					$(RAYCASTING_PATH)ray_casting.c			\
					$(RAYCASTING_PATH)ray_casting_utils.c	\
					$(RAYCASTING_PATH)calc_ray_casting.c		\
					$(RAYCASTING_PATH)texture_calcs_0.c		\
					$(RAYCASTING_PATH)texture_calcs_1.c		\
					$(UTILS_PATH)colour_encoding_util.c		\
					$(UTILS_PATH)params_utils.c					\
					$(UTILS_PATH)t_position_utils.c					\
					$(UTILS_PATH)ray_casting_utils.c					\
					$(WINDOW_PATH)window.c					\

OBJS			:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS			:=	$(addprefix $(SRC_DIR)/,$(SRCS))

all:	$(NAME)

$(NAME): $(LIBFT) $(MLIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS) -lm

$(MLIBX):
	make -C $(MLIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(DESTROY_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(INPUT_VALIDATION_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(KEYSTROKES_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(RAYCASTING_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(UTILS_PATH))
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(WINDOW_PATH))
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS) $(MLX_FLAGS)

clean:
	make clean -C $(MLIBX_PATH)
	make clean -C $(LIBFT_PATH)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re:	fclean all

run: all
	clear
	./$(NAME) $$MAP

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $$MAP

.PHONY:	all clean fclean re go valgrind
