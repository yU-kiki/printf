/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_case_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:01:10 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/10 18:01:10 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		info_case_c(char c, t_info info)
{
	int	len;
	int	space;

	if (info.width == INT_MAX)
		return (-1);
	if (info.zero == true || info.dot == true)
		return (-1);
	space = ' ';
	len = 0;
	len += (info.minus ? ft_putchar(c) : 0);
	while (len < (info.minus ? info.width : info.width - 1))
		len += ft_putchar(space);
	len += (info.minus ? 0 : ft_putchar(c));
	return (len);
}
