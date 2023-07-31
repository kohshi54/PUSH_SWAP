/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:58:44 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/07/31 18:58:44 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rb(t_stack **list)
{
	rotate(list);
}

void	do_ra(t_stack **list)
{
	rotate(list);
}

void	do_rr(t_stack **list_a, t_stack **list_b)
{
	rotate(list_a);
	rotate(list_b);
}

void	do_rrb(t_stack **list)
{
	reverse_rotate(list);
}

void	do_rra(t_stack **list)
{
	reverse_rotate(list);
}
