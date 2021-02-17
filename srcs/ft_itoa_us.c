/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_us.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagrant </var/mail/vagrant>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:15:16 by vagrant           #+#    #+#             */
/*   Updated: 2021/02/17 19:15:16 by vagrant          ###   ########.fr       */
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
	i = 0;
	while (i < len)
	{
		dst[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}