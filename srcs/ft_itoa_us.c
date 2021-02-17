/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_us.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:15:16 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 19:15:16 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_us(unsigned int n)
{
	char	*dst;
	size_t	len;
	int		i;

	len = get_digits(n);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		dst[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	dst[len] = '\0';
	return (dst);
}
