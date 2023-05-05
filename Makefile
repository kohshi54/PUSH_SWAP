NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = push_swap.c push_swap_utils.c
OBJS = $(SRCS:%.c=%.o)

LIBFT = libft.a
LIBFT_DIR = LIBFT/

INCLUDES = push_swap.h

LIBRARY = -L./$(LIBFT_DIR) -lft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

$(LIBFT) : $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean : 
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : clean fclean re all

.SECONDARY :

