/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:57 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/05/12 16:51:00 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*zero;
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

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
	t_stack	*zero_a;
	t_stack	*one_a;
	t_stack	*two_a;
	t_stack	*zero_b;
	t_stack	*one_b;

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
	t_stack	*head;

	head = (*list)->next;
	if (head->index == 0)
		return ;
	swap(&((*list)->prev));
	*list = head;
}

void	reverse_rotate(t_stack **list)
{
	t_stack	*last;

	last = (*list)->prev->prev;
	if ((*list)->next->index == 0)
		return ;
	swap(&last);
	*list = last;
}
