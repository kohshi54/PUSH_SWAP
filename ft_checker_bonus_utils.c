/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:58:40 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/07/31 18:58:40 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **list)
{
	t_stack	*head;

	head = (*list)->next;
	swap(list);
	*list = head;
}

void	do_sb(t_stack **list)
{
	t_stack	*head;

	head = (*list)->next;
	swap(list);
	*list = head;
}

void	do_ss(t_stack **list_a, t_stack **list_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = (*list_a)->next;
	swap(list_a);
	*list_a = head_a;
	head_b = (*list_b)->next;
	swap(list_b);
	*list_b = head_b;
}

void	do_pa(t_info *info_a, t_info *info_b)
{
	if (info_b->head->next == info_b->head)
		return ;
	if (info_b->head->index > info_a->max)
		info_a->max = info_b->head->index;
	if (info_b->head->index < info_a->min)
		info_a->min = info_b->head->index;
	if (info_b->head->index == info_b->max)
		info_b->max = find_max(info_b->head->next);
	if (info_b->head->index == info_b->min)
		info_b->min = find_min(info_b->head->next);
	info_a->size++;
	info_b->size--;
	push(&(info_b->head), &(info_a->head));
}

void	do_pb(t_info *info_a, t_info *info_b)
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
}
