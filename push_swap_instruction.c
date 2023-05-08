#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack *zero;
	t_stack *one;
	t_stack *two;
	t_stack *three;

	if (*list == (*list)->next->next)
		return ;

	zero = (*list)->prev;
	one = (*list);
	two = (*list)->next;
	three = (*list)->next->next;

	zero->next = two;
	two->prev = zero;

	two->next = one;
	one->prev = two;

	one->next = three;
	three->prev = one;
}

void	push(t_stack **list_a, t_stack **list_b)
{
	t_stack *zero_a;
	t_stack *one_a;
	t_stack *two_a;
	t_stack *zero_b;
	t_stack *one_b;

	zero_a = (*list_a)->prev;
	one_a = (*list_a);
	two_a = (*list_a)->next;
	zero_b = (*list_b)->prev;
	one_b = (*list_b);

	zero_a->next = two_a;
	two_a->prev = zero_a;

	zero_b->next = one_a;
	one_a->prev = zero_b;
	one_a->next = one_b;
	one_b->prev = one_a;

	(*list_a) = two_a;
	(*list_b) = one_a;
}

void	rotate(t_stack **list)
{
	t_stack *head;

	head = (*list)->next;
	if (head->index == 0)
		return ;
	swap(&((*list)->prev));
	*list = head;
}

void	reverse_rotate(t_stack **list)
{
	t_stack *last;

	last = (*list)->prev->prev;
	if ((*list)->next->index == 0)
		return ;
	swap(&last);
	*list = last;
}

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

void	push_b(t_info *info_a, t_info *info_b)
{
	if (info_a->head->next == info_a->head)
		return ;
	if (info_a->head->index > info_b->max)
		info_b->max = info_a->head->index;
	if (info_a->head->index < info_b->min)
		info_b->min = info_a->head->index;
	
	if (info_a->head->index == info_a->max)
		info_a->max = find_max(info_a->head->next);
	if (info_a->head->index == info_a->min)
		info_a->min = find_min(info_a->head->next);

	info_a->size--;
	info_b->size++;
	push(&(info_a->head), &(info_b->head));
	ft_printf("pb\n");
}

void	push_a(t_info *info_a, t_info *info_b)
{
	if (info_b->head->next == info_b->head)
		return ;
	if (info_b->head->index > info_a->max)
		info_a->max = info_b->head->index;
	if (info_b->head->num < info_a->min)
		info_a->min = info_b->head->index;
	
	if (info_b->head->index == info_b->max)
		info_b->max = find_max(info_b->head->next);
	if (info_b->head->index == info_b->min)
		info_b->min = find_min(info_b->head->next);
	
	info_a->size++;
	info_b->size--;

	push(&(info_b->head), &(info_a->head));
	ft_printf("pa\n");
}

void	swap_b(t_stack **list)
{
	t_stack	*head;

	head = (*list)->next;
	swap(list);
	*list = head;
	ft_printf("sb\n");
}

void	swap_a(t_stack **list)
{
	t_stack	*head;

	head = (*list)->next;
	swap(list);
	*list = head;
	ft_printf("sa\n");
}
