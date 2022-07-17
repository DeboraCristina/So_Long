NAME		=	so_long

PATH_PREFIX	=	src/

EXT_SUFFIX	=	.c

SRCS		=	solong events window_manage map_manager

FULL_SRCS	=	$(addsuffix $(EXT_SUFFIX), $(addprefix $(PATH_PREFIX), $(SRCS)))

OBJS		=	$(FULL_SRCS:%.c=%.o)

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
	@$(COMPILER) $(FLAGS) -I./ -I$(LFTPATH) -I$(MLX_PATH) -c $< -o $(<:%.c=%.o)

$(NAME):	$(LFTNAME) $(OBJS) $(MLX_PATH)
	@$(MAKENOPRINT) -C $(MLX_PATH)
	@$(COMPILER) $(OBJS) $(MLX_FLAGS) $(LFTFLAGS) -o $(NAME)

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
