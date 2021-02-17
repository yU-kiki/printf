/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:15:11 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/18 00:15:11 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_hex(unsigned int n, char a_size)
{
	char	*dst;
	int		len;
	int		i;

	len = get_digits_base(n, 16);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		dst[i] = n % 16 + (n % 16 < 10 ? '0' : a_size - 10);
		n /= 16;
		i--;
	}
	dst[len] = '\0';
	return (dst);
}
