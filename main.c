/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikeda <yikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:45:03 by yikeda            #+#    #+#             */
/*   Updated: 2021/02/10 15:52:44 by yikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	printf("printf(\"%%%%\")\n");
	int len1 = ft_printf("[%%]");
	printf("\nlen = %d\n\n", len1);

	printf("printf(\"[%%3c]\", 'a')\n");
	int len2 = ft_printf("[%3c]", 'a');
	printf("\nlen = %d\n\n", len2);


	printf("printf(\"[%%-3c]\", 'a')\n");
	int len3 = ft_printf("[%-3c]", 'a');
	printf("\nlen = %d\n\n", len3);

	return (0);
}
