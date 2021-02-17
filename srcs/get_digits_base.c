/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digits_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:42:19 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 19:42:19 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_digits_base(unsigned int n, unsigned int base)
{
	int		digits;

	digits = 1;
	while (n >= base)
	{
		digits++;
		n /= base;
	}
	return (digits);
}
