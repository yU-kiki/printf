/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_case_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:45:01 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/11 15:45:01 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prec_str(char *str, t_info info)
{
	int		prec;

	prec = info.prec;
	if (!str)
		return (info.dot ? ft_strndup("(null)", prec) : ft_strdup("(null)"));
	else
		return (info.dot ? ft_strndup(str, prec) : ft_strdup(str));
}

int			info_case_s(char *src, t_info info)
{
	char	*str;
	int		len;

	if (!(str = prec_str(src, info)))
		return (-1);
	len = 0;
	len += (info.minus ? ft_putstr(str) : 0);
	while (len < (info.minus ? info.width : info.width - ft_strlen(str)))
		len += (info.zero ? ft_putchar('0') : ft_putchar(' '));
	len += (info.minus ? 0 : ft_putstr(str));
	free(str);
	return (len);
}
