/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:10:04 by tyonezaw          #+#    #+#             */
/*   Updated: 2023/07/18 10:27:21 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (*(s1 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return ((int)((char)*(s1 + i) - (char)*(s2 + i)));
		i++;
	}
	if (*(s1 + i) != *(s2 + i))
		return ((int)((char)*(s1 + i) - (char)*(s2 + i)));
	return (0);
}
