NAME		=	so_long

PATH_PREFIX	=	src/

EXT_SUFFIX	=	.c

SRCS		=	solong events window_manage \
				src_map/map_manager src_map/verify_map \
				src_map/verify_map_utils src_map/map_configs \
				src_objsconfigs/ft_objadd_back \
				src_objsconfigs/ft_newobj \
				src_objsconfigs/ft_objlast

FULL_SRCS	=	$(addsuffix $(EXT_SUFFIX), $(addprefix $(PATH_PREFIX), $(SRCS)))

OBJS		=	$(FULL_SRCS:%.c=%.o)

INCLUDE		=	Includes/

COMPILER	=	cc

FLAGS		=	-Wall -Wextra -Werror

REMOVE		=	rm -f

AR			=	ar -rc

MAKENOPRINT	=	make --no-print-directory

MLX_PATH	=	minilibx-linux/

MLX_FLAGS	=	-Iminilibx-linux -Lminilibx-linux -lmlx_Linux  -lXext -lX11 -lm

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
