/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus_utils3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:58:48 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/07/31 18:58:49 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_stack **list_a, t_stack **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
}
