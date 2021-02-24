/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_case_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:27:29 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 15:27:29 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_numstr_u(unsigned int n, t_info info)
{
	char	*ret;
	char	*zeros;
	char	*tmp;
	int		len;
	int		i;

	if (info.dot && info.prec == 0 && n == 0)
		return (ft_strdup(""));
	if (!info.dot || info.prec < get_digits(n))
		return (ft_itoa_us(n));
	len = info.prec - get_digits(n);
	if (!(zeros = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		zeros[i] = '0';
		i++;
	}
	zeros[i] = '\0';
	tmp = ft_itoa_us(n);
	ret = ft_strjoin(zeros, tmp);
	return (freeturn(&zeros, &tmp, ret));
}

static int	ft_width_u(t_info info, char *num_str)
{
	int		len;
	int		digits;

	digits = ft_strlen(num_str);
	len = 0;
	if (info.zero && !info.dot)
	{
		while (len < info.width - digits)
			len += ft_putchar('0');
		len += ft_putstr(num_str);
	}
	else
	{
		len += (info.minus ? ft_putstr(num_str) : 0);
		while (len < (info.minus ? info.width : info.width - digits))
			len += ft_putchar(' ');
		len += (info.minus ? 0 : ft_putstr(num_str));
	}
	return (len);
}

int			info_case_u(unsigned int n, t_info info)
{
	char	*num_str;
	int		len;

	if (!(num_str = get_numstr_u(n, info)))
		return (-1);
	len = 0;
	len += ft_width_u(info, num_str);
	free(num_str);
	return (len);
}
