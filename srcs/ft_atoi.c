/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:19:01 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/10 15:19:01 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	ans;

	i = 0;
	ans = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
		if (ans > 2147483647)
			return (-1);
	}
	return ((int)ans);
}
