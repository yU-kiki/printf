/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:13:50 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 19:13:50 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_digits(unsigned int n)
{
	int		digits;

	digits = 1;
	while (n >= 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}
