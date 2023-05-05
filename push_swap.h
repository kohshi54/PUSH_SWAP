#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"

typedef struct stack
{
	int num;
	// int coordinate;
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

void	rotate_a(t_stack **list);

// void	push_b(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b, t_info *info_a, t_info *info_b);

// void	push_a(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b, t_info *info_a, t_info *info_b);

t_stack	*init_node(void);
t_stack	*add_list(char *str, t_stack *prev);
t_stack	*make_list(char *argv[], t_info *info);
t_stack	*make_b();
void	free_all(t_stack *a, t_stack *b);

void	print_list(t_stack *list);
int find_min(t_stack *list);
int	find_max(t_stack *list);

# endif