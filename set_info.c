/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:20:54 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/09 20:20:54 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	check_format(const char *str)
{
	while (*str == '-' || *str == '0')
		str++;
	if (*str == '*')
		str++;
	else
	{
		while ('0' <= *str && *str <= '9')
			str++;
	}
	if (*str == '.')
	{
		str++;
		if (*str == '*')
			str++;
		else
		{
			while ('0' <= *str && *str <= '9')
				str++;
		}
		return (ft_is_strchr("%cspdiuxX", *str));
	}
}

void	set_flag(const char **ptr, t_info *info)
{
	while (**ptr == '-' || **ptr == '0')
	{
		if (**ptr == '-')
		{
			info->minus = true;
			info->zero = false;
		}
		if (**ptr == '0' && !info->minus)
			info->zero = true;
		(*ptr)++;
	}
}

void	set_width(const char **ptr, t_info *info, va_list ap)
{
	int	tmp;

	if (**ptr == '*')
	{
		tmp = (int)va_arg(ap, int);
		if (tmp < 0)
		{
			if (!info->minus)
			{
				info->minus = true;
				info->zero = false;
			}
			info->width = -tmp;
		}
		else
			info->width = tmp;
		(*ptr)++;
	}
	else if ('0' <= **ptr && **ptr <= '9')
	{
		info->width = ft_atoi(*ptr);
		while ('0' <= **ptr && **ptr <= '9')
			(*ptr)++;
	}
}	

bool	set_info(const char **ptr, t_info *info, va_list ap)
{
	(*ptr)++;
	if (!check_format(*ptr))
		return (false);
	info->zero = false;
	info->minus = false;
	info->width = -1;
	info->dot = false;
	info->prec = 0;
	info->spec = 0;
	set_flag(ptr, info);
	set_width(ptr, info, ap);
	set_precision(ptr, info, ap);
	info->spec = **ptr;
	return (true);
}