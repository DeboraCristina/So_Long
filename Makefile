NAME		=	so_long

SRCS		=	main.c

OBJS		=	$(SRCS:%.c=%.o)

COMPILER	=	cc

FLAGS		=	-Wall	-Wextra	-Werror

REMOVE		=	rm -f

AR			=	ar -rc

%.o:	%.c
	$(COMPILER) $(FLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $(<:%.c=%.o)

$(NAME):	$(OBJS)
	$(COMPILER) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

all:	$(NAME)

clean:
	@$(REMOVE) $(OBJS)

fclean:	clean
	@$(REMOVE) $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re

