/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagrant </var/mail/vagrant>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:13:50 by vagrant           #+#    #+#             */
/*   Updated: 2021/02/17 19:13:50 by vagrant          ###   ########.fr       */
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
