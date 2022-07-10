NAME		=	so_long

SRCS		=	main.c

OBJS		=	$(SRCS:%.c=%.o)

COMPILER	=	cc

FLAGS		=	-Wall -Wextra -Werror

REMOVE		=	rm -f

AR			=	ar -rc

MAKENOPRINT	=	make --no-print-directory

MLX_PATH	=	minilibx-linux/

%.o:	%.c
	@$(COMPILER) $(FLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $(<:%.c=%.o)

$(NAME):	$(OBJS) $(MLX_PATH)
	@$(MAKENOPRINT) -C $(MLX_PATH)
	@$(COMPILER) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

all:	$(NAME)

clean:
	@$(MAKENOPRINT) clean -C $(MLX_PATH)
	@$(REMOVE) $(OBJS)

fclean:	clean
	@$(REMOVE) $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re

