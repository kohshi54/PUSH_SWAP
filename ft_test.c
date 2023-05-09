#include "push_swap.h"

/* 
#include <stdio.h>
void	print_list(t_stack *list)
{
	ft_printf("-----print start----\n");
	while (list->index)
	{
		printf("num: %ld, index: %d\n", list->num, list->index);
		list = list->next;
	}
	printf("num: %ld, index: %d\n", list->num, list->index);
	ft_printf("-----print end------\n");
}

void	print_forward(t_stack *list)
{
	t_stack	*head;

	ft_printf("-----forward start----\n");
	head = list;
	while (list->index)
	{
		ft_printf("num: %d, index: %d\n", list->num, list->index);
		list = list->next;
	}
	ft_printf("num: %d, index: %d\n", list->num, list->index);
	if (list->next->index == head->index)
		ft_printf("cycle yes\n");
	ft_printf("-----forward end------\n");
}

void	print_backward(t_stack *list)
{
	t_stack	*head;

	ft_printf("-----backward start----\n");
	list = list->prev->prev;
	head = list;
	while (list->index)
	{
		ft_printf("num: %d, index: %d\n", list->num, list->index);
		list = list->prev;
	}
	ft_printf("num: %d, index: %d\n", list->num, list->index);
	if (list->prev->index == head->index)
		ft_printf("cycle yes\n");
	ft_printf("-----backward end------\n");
}
*/