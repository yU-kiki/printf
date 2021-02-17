/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:14:59 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 19:14:59 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int nbr)
{
	char			*dst;
	unsigned int	n;
	int				len;
	int				i;

	n = (nbr < 0 ? -nbr : nbr);
	len = get_digits(n) + (nbr < 0 ? 1 : 0);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		if (i == 0 && nbr < 0)
			dst[i] = '-';
		else
		{
			dst[i] = n % 10 + '0';
			n /= 10;
		}
		i--;
	}
	dst[len] = '\0';
	return (dst);
}
