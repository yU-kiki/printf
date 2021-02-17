/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_case_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagrant </var/mail/vagrant>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:59:49 by vagrant           #+#    #+#             */
/*   Updated: 2021/02/17 23:59:49 by vagrant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char get_numstr_xX(unsigned int n, char a_size, t_info info)
{
	char	*ret;
	char	*zeros;
	char	*tmp;
	int		len;
	int		i;

	if (info.dot && info.prec == 0 && n == 0)
		return (ft_strdup(""));
	len = info.prec - get_digits_base(n, 16);
	len = (len < 0 ? 0 : len);
	if (!(zeros = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		zeros[i++] = '0';
	zeros[i] = '\0';
	tmp = ft_itoa_hex(n, a_size);
	ret = ft_strjoin(zeros, tmp);
	return (freeturn(&zeros, &tmp, ret));
}

static int	ft_width_xX(t_info info, char *num_str)
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

int			info_case_xX(unsigned int n, char a_size, t_info info)
{
	char	*num_str;
	int		len;

	if (!(num_str = get_numstr_xX(n, a_size, info)))
		return (-1);
	len = 0;
	len += ft_width_xX(info, num_str);
	free(num_str);
	return (len);
}
