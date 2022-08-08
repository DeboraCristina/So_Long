NAME		=	so_long

PATH_PREFIX	=	src/

EXT_SUFFIX	=	.c

SRCS_OBJS	=	$(addprefix src_objsconfigs/, config_obj \
				ft_destroy_images)

SRCS_MAPS	=	$(addprefix src_map/, verify_map \
				map_configs verify_map_utils)

SRCS_MOVE	=	$(addprefix src_movements/, movements_utils)

SRCS		=	solong events window_manager map_manager \
				reder_images movements_manager

FULL_SRCS	=	$(addsuffix $(EXT_SUFFIX), \
				$(addprefix $(PATH_PREFIX), \
				$(SRCS) $(SRCS_MAPS) $(SRCS_OBJS) $(SRCS_MOVE)))

OBJS		=	$(FULL_SRCS:%.c=%.o)

INCLUDE		=	includes/

COMPILER	=	cc

FLAGS		=	-Wall -Wextra -Werror

REMOVE		=	rm -f

AR			=	ar -rc

MAKENOPRINT	=	make --no-print-directory

MLX_PATH	=	mlx/
MLX_FLAGS	=	-I$(MLX_PATH) -L$(MLX_PATH) -lmlx  -lXext -lX11 -lm

# MLX_FLAGS	=	-lmlx  -lXext -lX11 -lm

LFTNAME		=	libft_bonus.a

LFTPATH		= ./Libft

LFTFLAGS	=	-I$(LFTPATH) -L$(LFTPATH) -lft_bonus

%.o:	%.c
	@$(COMPILER) $(FLAGS) -I$(INCLUDE) -I$(LFTPATH) -I$(MLX_PATH) -g3 -c $< -o $(<:%.c=%.o)

$(NAME):	$(LFTNAME) $(OBJS) $(MLX_PATH)
	@$(MAKENOPRINT) -C $(MLX_PATH)
	@$(COMPILER) $(OBJS) $(MLX_FLAGS) $(LFTFLAGS) -g3 -o $(NAME)

$(LFTNAME):
	@$(MAKENOPRINT) bonus -C $(LFTPATH)

all:	$(NAME)

clean:
	@$(MAKENOPRINT) clean -C $(MLX_PATH)
	@$(REMOVE) $(OBJS)

fclean:	clean
	@$(MAKENOPRINT) fclean -C $(LFTPATH)
	@$(REMOVE) $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
