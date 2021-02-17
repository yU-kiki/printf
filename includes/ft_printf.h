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
# include <stdio.h>

typedef struct	s_info
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
int				info_case_c(char c, t_info info);
int				info_case_s(char *src, t_info info);
int				info_case_p(void *ptr, t_info info);
int				info_case_di(int n, t_info info);
int				info_case_u(unsigned int n, t_info info);
int				info_case_xX(unsigned int n, char a_size, t_info info);

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_strlen(const char *src);
bool			ft_is_strchr(char *str, char c);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, int n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_itoa(int nbr);
char			*ft_itoa_us(unsigned int n);
char			*ft_itoa_hex(unsigned int n, char a_size);
int				get_digits(unsigned int n);
int				get_digits_base(unsigned int n, unsigned int base);
int				ft_atoi(const char *str);
char			*freeturn(char **s1, char **s2, char *ret);

#endif
