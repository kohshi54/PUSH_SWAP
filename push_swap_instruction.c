#include "push_swap.h"

/*
t_stack *swap(t_stack *list)
{
	t_stack *zero;
	t_stack *one;
	t_stack *two;
	t_stack *three;
	zero = list->prev;
	one = list;
	two = list->next;
	three = list->next->next;
	zero->next = two;
	two->prev = zero;
	two->next = one;
	one->prev = two;
	one->next = three;
	three->prev = one;
	return (two);
}
*/

void	swap(t_stack **list)
{
	t_stack *zero;
	t_stack *one;
	t_stack *two;
	t_stack *three;

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

	*list = two;
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

/*
t_stack *rotate(t_stack *list)
{
	t_stack *head;
	head = list->next;
	swap(list->prev);
	return (head);
}
*/

void	rotate(t_stack **list)
{
	t_stack *head;

	head = (*list)->next;
	swap(&((*list)->prev));
	*list = head;
}

/*
t_stack *reverse_rotate(t_stack *list)
{
	t_stack *head;
	head = list->prev->prev;
	swap(list->prev->prev);
	return (head);
}
*/

void	reverse_rotate(t_stack **list)
{
	t_stack *last;

	last = (*list)->prev->prev;
	swap(&last);
	*list = (*list)->prev;
}

void	rotate_a(t_stack **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	push_b(t_stack **a, t_stack **b, t_info *info_a, t_info *info_b)
{
	if ((*a)->next == (*a))
		return ;
	if ((*a)->num > info_b->max)
		info_b->max = (*a)->num;
	if ((*a)->num < info_b->min)
		info_b->min = (*a)->num;
	
	if ((*a)->num == info_a->max)
		info_a->max = find_max((*a)->next);
	if ((*a)->num == info_a->min)
		info_a->min = find_min((*a)->next);
	
	push(a, b);
	info_a->size--;
	info_b->size++;
	ft_printf("pb\n");
}

void	push_a(t_stack **a, t_stack **b, t_info *info_a, t_info *info_b)
{
	if ((*b)->next == (*b))
		return ;
	if ((*b)->num > info_a->max)
		info_a->max = (*b)->num;
	if ((*b)->num < info_a->min)
		info_a->min = (*b)->num;
	
	if ((*b)->num == info_b->max)
		info_b->max = find_max((*b)->next);
	if ((*b)->num == info_b->min)
		info_b->min = find_min((*b)->next);

	push(b, a);
	info_a->size++;
	info_b->size--;
	ft_printf("pa\n");
}
