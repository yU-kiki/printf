/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_case_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:27:21 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/17 15:27:21 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_numstr_di(int n, t_info info)
{
	char	*ret;
	char	*zeros;
	char	*tmp;
	int		len;
	int		i;

	if (info.dot && info.prec == 0 && n == 0)
		return (ft_strdup(""));
	if (!info.dot || info.prec < (n < 0 ? get_digits(-n) + 1 : get_digits(n)))
		return (ft_itoa(n));
	len = (n < 0 ? info.prec - get_digits(-n) + 1 : info.prec - get_digits(n));
	zeros = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		if (i == 0 && n < 0)
			zeros[i] = '-';
		else
			zeros[i] = '0';
		i++;
	}
	zeros[i] = '\0';
	tmp = (n < 0 ? ft_itoa_us(-n) : ft_itoa_us(n));
	ret = ft_strjoin(zeros, tmp);
	return (freeturn(&zeros, &tmp, ret));
}

static int	ft_width_di(int n, t_info info, char *num_str)
{
	int		len;
	int		digits;

	digits = ft_strlen(num_str);
	len = 0;
	if (info.zero && !info.dot)
	{
		len += (n < 0 ? ft_putchar(*num_str) : 0);
		while (len < info.width - digits + (n < 0 ? 1 : 0))
			len += ft_putchar('0');
		len += ft_putstr(n < 0 ? &num_str[1] : &num_str[0]);
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

int			info_case_di(int n, t_info info)
{
	char	*num_str;
	int		len;

	if (!(num_str = get_numstr_di(n, info)))
		return (-1);
	len = 0;
	len += ft_width_di(n, info, num_str);
	free(num_str);
	return (len);
}
