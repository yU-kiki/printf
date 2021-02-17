/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:35:27 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/09 18:35:27 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_proc_per(const char **ptr, va_list ap, int left)
{
	int		len;
	t_info	info;

	if (!set_info(ptr, &info, ap))
		return (-1);
	if (info.spec == '%')
		len = info_case_c('%', info);
	if (info.spec == 'c')
		len = info_case_c(va_arg(ap, int), info);
	if (info.spec == 's')
		len = info_case_s(va_arg(ap, char *), info);
	if (info.spec == 'p')
		len = info_case_p(va_arg(ap, void *), info);
	if (info.spec == 'd' || info.spec == 'i')
		len = info_case_di(va_arg(ap, int), info);
	if (info.spec == 'u')
		len = info_case_u(va_arg(ap, unsigned int), info);
	if (info.spec == 'x' || info.spec == 'X')
		len = info_case_x(va_arg(ap, unsigned int), info.spec - 23, info);
	if (len > left)
		return (-1);
	return (len);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;
	int		ret;
	int		left;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		left = INT_MAX - len - 1;
		if (*fmt == '%')
		{
			if ((ret = ft_proc_per(&fmt, ap, left)) == -1)
				return (-1);
			len += ret;
		}
		else if (left < 1)
			return (-1);
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (len);
}
