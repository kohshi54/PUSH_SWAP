/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:37:11 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/07/31 14:23:01 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static bool	overflow_min_checker(long num, const char *str)
{
	if (num > (INT_MIN / 10) * -1)
		return (1);
	else if (num == ((INT_MIN / 10) * -1) \
				&& (*str - '0') > ((INT_MIN % 10) * -1))
		return (1);
	return (0);
}

static bool	overflow_max_checker(long num, const char *str)
{
	if (num > (INT_MAX / 10))
		return (1);
	else if (num == (INT_MAX / 10) && (*str - '0') > (INT_MAX % 10))
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') \
					|| (c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
}

char	skip_space_and_operator(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	char	neg_flg;
	long	num;

	num = 0;
	neg_flg = skip_space_and_operator(&str);
	if (*str == '\0')
		return (WRONG_NUM);
	while (ft_isdigit(*str))
	{
		if (neg_flg == -1)
		{
			if (overflow_min_checker(num, str))
				return (WRONG_NUM);
		}
		else
			if (overflow_max_checker(num, str))
				return (WRONG_NUM);
		num = (num * 10) + (*str++ - '0');
	}
	if (*str != '\0')
		return (WRONG_NUM);
	return ((int)(num * neg_flg));
}
