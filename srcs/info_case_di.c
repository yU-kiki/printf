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

static int	*get_numstr_di(int n, t_info info)
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

int			info_case_di(int n, t_info info)
{
	char	*num
	int		len;

	if (!(num_str = get_numstr_di(n, info)))
		return (-1);
	len = 0;
}