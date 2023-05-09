#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"

typedef struct stack
{
	long num;
	int index;
	struct stack *next;
	struct stack *prev;
}	t_stack;

typedef struct info
{
	t_stack *head;
	int	size;
	int	max;
	int min;
}	t_info ;

void	swap(t_stack **list);
void	push(t_stack **list_a, t_stack **list_b);
void	rotate(t_stack **list);
void	reverse_rotate(t_stack **list);

void	swap_b(t_stack **list);
void	swap_a(t_stack **list);

void	push_b(t_info *info_a, t_info *info_b);
void	push_a(t_info *info_a, t_info *info_b);

void	rotate_b(t_stack **list);
void	rotate_a(t_stack **list);
void 	rotate_a_and_b(t_stack **list_a, t_stack **list_b);

void	reverse_rotate_b(t_stack **list);
void	reverse_rotate_a(t_stack **list);

t_stack	*init_node(void);
t_stack	*add_list(char *str, t_stack *prev);
t_stack *make_list(char *argv[]);
void	make_b(t_info *info_a, t_info *info_b);
void	make_a(t_info *info_a, char *argv[]);
void	free_all(t_stack *a, t_stack *b);

int		find_min(t_stack *list);
int		find_max(t_stack *list);
void	index_compress(t_info *info_a);
void	input_validation(t_info info_a);

void	sort_by_input_number(t_info *info_a, t_info *info_b);
size_t	get_count_of_less_than_pivot(t_stack *list, int pivot);
int		find_nearest_target(t_stack *list, int pivot);
size_t	search_forward(t_stack *list, int target);
size_t	search_backward(t_stack *list, int target);
void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, int pivot, int element);
void	find_largest_and_push_a(t_info *info_a, t_info *info_b);

// void	print_list(t_stack *list);

# endif