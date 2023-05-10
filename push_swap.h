#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"

typedef struct stack
{
	long			num;
	int				index;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

typedef struct info
{
	t_stack	*head;
	int		size;
	int		max;
	int		min;
}	t_info;

/* ft_operatoin.c */
void	swap(t_stack **list);
void	push(t_stack **list_a, t_stack **list_b);
void	rotate(t_stack **list);
void	reverse_rotate(t_stack **list);

/* ft_operation2.c */
void	swap_b(t_stack **list);
void	swap_a(t_stack **list);
void	push_b(t_info *info_a, t_info *info_b);
void	push_a(t_info *info_a, t_info *info_b);

/* ft_operation3.c */
void	rotate_b(t_stack **list);
void	rotate_a(t_stack **list);
void	rotate_a_and_b(t_stack **list_a, t_stack **list_b);
void	reverse_rotate_b(t_stack **list);
void	reverse_rotate_a(t_stack **list);
void	reverse_rotate_a_and_b(t_stack **list_a, t_stack **list_b);

/* ft_create_list.c */
t_stack	*init_node(void);
t_stack	*add_list(char *str, t_stack *prev);
t_stack	*make_list(char *argv[]);
void	make_stack_b(t_info *info_a, t_info *info_b);
void	make_stack_a(t_info *info_a, char *argv[]);

/* ft_prepare.c */
void	free_all(t_stack *list_a, t_stack *list_b);
void	make_index(t_info *info_a);
void	put_error_and_free_and_exit(t_stack *list);
void	validate_input(t_info info_a);

/* ft_search.c */
int		find_min(t_stack *list);
int		find_max(t_stack *list);
size_t	search_forward(t_stack *list, int target);
size_t	search_backward(t_stack *list, int target);

/* ft_sort.c */
size_t	check_if_list_is_sorted(t_info info_a);
void	sort_when_three(t_info *info_a);
void	sort_from_four_to_six(t_info *info_a, t_info *info_b);
void	sort_above_seven(t_info *info_a, t_info *info_b);
void	sort_by_input_number(t_info *info_a, t_info *info_b);

/* ft_push_to_a.c */
int		find_largest_or_second_largest(t_stack *list, int max);
void	find_largest_and_push_a(t_info *info_a, t_info *info_b);

/* ft_push_to_b.c */
size_t	get_count_of_less_than_pivot(t_stack *list, int pivot);
int		find_nearest_target(t_stack *list, int pivot);
void	find_less_than_pivot_and_push_b(t_info *info_a, t_info *info_b, int pivot, int element);

/* ft_test.c */
void	print_list(t_stack *list);
// void	print_forward(t_stack *list);
// void	print_backward(t_stack *list);

#endif