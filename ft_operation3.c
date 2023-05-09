#include "push_swap.h"

void	rotate_b(t_stack **list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rotate_a(t_stack **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void rotate_a_and_b(t_stack **list_a, t_stack **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}

void	reverse_rotate_b(t_stack **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}

void	reverse_rotate_a(t_stack **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}
