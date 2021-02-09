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

static int	ft_proc_per(const char **ptr, va_list ap)
{
	int		len;
	t_info	info;

	if (!set_info(ptr, &info, ap))
		return (-1);

}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int			len;
	int			ret;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if ((ret = ft_proc_per(&fmt, ap)) == -1)
				return (-1);
			len += ret;
		}
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (len);
}