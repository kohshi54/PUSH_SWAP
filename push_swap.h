#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"

typedef struct stack
{
	int num;
	int coordinate;
	struct stack *next;
	struct stack *prev;
}	t_stack;

typedef struct info
{
	t_stack *stack_head;
	int	size;
	int	max;
	int min;
}	t_info ;

void	rotate(t_stack **list);
void	reverse_rotate(t_stack **list);

void	rotate_b(t_stack **list);
void	rotate_a(t_stack **list);

void	reverse_rotate_b(t_stack **list);
void	reverse_rotate_a(t_stack **list);

// void	push_b(t_stack **a, t_stack **b);
// void	push_b(t_stack **a, t_stack **b, t_info *info_a, t_info *info_b);
void	push_b(t_info *info_a, t_info *info_b);

// void	push_a(t_stack **a, t_stack **b);
// void	push_a(t_stack **a, t_stack **b, t_info *info_a, t_info *info_b);
void	push_a(t_info *info_a, t_info *info_b);

void	swap_b(t_stack **list);
void	swap_a(t_stack **list);

t_stack	*init_node(void);
t_stack	*add_list(char *str, t_stack *prev);
// t_stack	*make_list(char *argv[], t_info *info);
t_stack *make_list(char *argv[]);
// t_stack	*make_b();
void	make_b(t_info *info_b);
void	make_a(t_info *info_a, char *argv[]);
void	free_all(t_stack *a, t_stack *b);

void	print_list(t_stack *list);
int find_min(t_stack *list);
int	find_max(t_stack *list);

// size_t	find_maximum(t_stack *list);
// size_t	find_shorter_path_to_max(t_stack *list, int max);
// size_t	search_backward(t_info *info);
size_t	search_backward(t_info *info, int target);
// size_t	search_forward(t_info *info);
size_t	search_forward(t_info *info, int target);

size_t	get_digit(int max);

// void	coordinate_compress(t_stack *list);
void	coordinate_compress(t_stack *list, t_info *info_a);

# endif