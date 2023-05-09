#include "push_swap.h"

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