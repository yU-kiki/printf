/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_case_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:27:06 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 15:27:06 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_p(uintptr_t n, t_info info)
{
	int		len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len + 2);
}

static char		*get_numstr_p(uintptr_t n, t_info info)
{
	char	*dst;
	int		len;
	int		i;

	len = len_p(n, info);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i == 0)
			dst[i] = '0';
		if (i == 1)
			dst[i] = 'x';
		else
		{
			dst[i] = (n % 16 < 10 ? n % 16 + '0' : n % 16 - 10 + 'a');
			n /= 16;
		}
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int				info_case_p(void *ptr, t_info info)
{
	char	*num_str;
	int		digits;
	int		len;

	if (!ptr && info.dot && info.prec == 0)
	{
		if (!(num_str = ft_strdup("0x")))
			return (-1);
	}
	else if (info.dot)
		return (-1);
	else if (!(num_str = get_numstr_p((uintptr_t)ptr, info)))
		return (-1);
	digits = ft_strlen(num_str);
	len = 0;
	len += (info.minus ? ft_putstr(num_str) : 0);
	while (len < (info.minus ? info.width : info.width - digits))
		len += ft_putchar(' ');
	len += (info.minus ? 0 : ft_putstr(num_str));
	free(num_str);
	return (len);
}
