NAME		=	so_long

# testes
SRCS		=	main.c

OBJS		=	$(SRCS:%.c=%.o)

COMPILER	=	cc

FLAGS		=	-Wall -Wextra -Werror

REMOVE		=	rm -f

AR			=	ar -rc

MAKENOPRINT	=	make --no-print-directory

MLX_PATH	=	minilibx-linux/

MLX_FLAGS	=	-Iminilibx-linux -I./src -Lminilibx-linux -lmlx_Linux  -lXext -lX11 -lm

LFTNAME		=	libft.a

LFTPATH		= ./Libft

LFTFLAGS	=	-I$(LFTPATH) -L$(LFTPATH) -lft

%.o:	%.c
	@$(COMPILER) $(FLAGS) $(MLX_FLAGS) $(LFTFLAGS) -c $< -o $(<:%.c=%.o)

$(NAME):	$(LFTNAME) $(OBJS) $(MLX_PATH)
	@$(MAKENOPRINT) -C $(MLX_PATH)
	$(COMPILER) $(OBJS) $(MLX_FLAGS) $(LFTFLAGS) -o $(NAME)

$(LFTNAME):
	@$(MAKENOPRINT) -C $(LFTPATH)

all:	$(NAME)

clean:
	@$(MAKENOPRINT) clean -C $(MLX_PATH)
	@$(REMOVE) $(OBJS)

fclean:	clean
	@$(MAKENOPRINT) fclean -C $(LFTPATH)
	@$(REMOVE) $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
