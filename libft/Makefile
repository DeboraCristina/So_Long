SRCS	=	ft_atoi.c		ft_bzero.c		ft_calloc.c		\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
			ft_isdigit.c	ft_isprint.c	ft_memchr.c		\
			ft_memcmp.c		ft_memcpy.c		ft_memmove.c	\
			ft_memset.c		ft_strchr.c		ft_split.c		\
			ft_strdup.c		ft_strlcat.c	ft_strlcpy.c	\
			ft_strlen.c		ft_strncmp.c	ft_strnstr.c	\
			ft_strrchr.c	ft_tolower.c	ft_toupper.c	\
			ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
			ft_putstr_fd.c	ft_substr.c	ft_strjoin.c		\
			ft_strtrim.c	ft_itoa.c	ft_strmapi.c		\
			ft_striteri.c

SRCS_B	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
			ft_lstclear.c	ft_lstiter.c

SRCS_M	=	ft_isupper.c		ft_rev_tab.c	\
			ft_utoa.c			ft_islower.c	\
			ft_u2hex.c			ft_lu2hex.c		\
			ft_strcmp.c			get_next_line.c	\
			ft_swap_int.c

NAME_PRINTF	=	libftprintf.a

LOCAL_PRINTF	=	ft_printf/

OBJS	=	$(SRCS:%.c=%.o)

OBJS_B	=	$(SRCS_B:%.c=%.o)

OBJS_M	=	$(SRCS_M:%.c=%.o)

NAME	=	libft.a

NAME_B	=	libft_bonus.a

HEADER	=	libft.h

CC		=	cc

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

%.o:	%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(OBJS_M) $(HEADER) $(NAME_PRINTF)
	@mv $(LOCAL_PRINTF)$(NAME_PRINTF) $(NAME)
	@ar -rc $(NAME) $(OBJS) $(OBJS_M)

$(NAME_B):	$(OBJS) $(OBJS_B) $(OBJS_M) $(HEADER) $(NAME_PRINTF)
	@mv $(LOCAL_PRINTF)$(NAME_PRINTF) $(NAME_B)
	@ar -rc $(NAME_B) $(OBJS) $(OBJS_B) $(OBJS_M)

$(NAME_PRINTF):
	@make --no-print-directory -C $(LOCAL_PRINTF)

all:	$(NAME)

bonus:	$(NAME_B)

clean:
	@make --no-print-directory clean -C $(LOCAL_PRINTF)
	@$(RM) $(OBJS) $(OBJS_B) $(OBJS_M)

fclean: clean
	@make --no-print-directory fclean -C $(LOCAL_PRINTF)
	@$(RM) $(NAME) $(NAME_B)

re:	fclean all

re_b:	fclean bonus

.PHONY: all clean fclean re bonus
