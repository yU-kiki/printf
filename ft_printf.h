/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:36:41 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/09 18:36:41 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_info
{
	bool	zero;
	bool	minus;
	int		width;
	bool	dot;
	int		prec;
	char	spec;
}				t_info;

int				ft_printf(const char *fmt, ...);

bool			set_info(const char **ptr, t_info *info, va_list ap);

int				ft_putchar(char c);
bool			ft_is_strchr(char *str, char c);
int				ft_atoi(const char *str);

#endif 