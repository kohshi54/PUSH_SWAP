ifndef BNS
NAME = push_swap
endif
ifdef BNS
NAME = checker
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_prepare.c ft_create_list.c \
		ft_search.c ft_push_to_b.c ft_push_to_a.c \
		ft_sort.c ft_operation.c ft_operation2.c ft_operation3.c

ifndef BNS
SRCS += push_swap.c
endif
ifdef BNS
SRCS += ft_checker_bonus.c ft_checker_bonus_utils.c ft_checker_bonus_utils2.c ft_checker_bonus_utils3.c
endif
OBJS = $(SRCS:%.c=%.o)

LIBFT = LIBFT/libft.a
LIBFT_DIR = LIBFT/

INCLUDES = push_swap.h

LIBRARY = -L./$(LIBFT_DIR) -lft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

$(LIBFT) : $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean : 
	rm -f $(OBJS) ft_checker_bonus.o ft_checker_bonus_utils.o ft_checker_bonus_utils2.o ft_checker_bonus_utils3.o
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME) checker
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

bonus : 
	@make BNS=1

.PHONY : clean fclean re all bonus
