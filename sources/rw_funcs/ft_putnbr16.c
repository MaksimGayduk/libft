/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:01:08 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:46:48 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hex_symbol(int n, t_bool char_case)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar((n - 10) + (char_case ? 'A' : 'a'));
}

void		ft_putnbr16(uintmax_t n, t_bool char_case, t_bool prefix)
{
	if (n < 16)
	{
		if (prefix)
		{
			ft_putchar('0');
			ft_putchar('x');
		}
		print_hex_symbol(n & 0xf, char_case);
		return ;
	}
	ft_putnbr16(n >> 4, char_case, prefix);
	print_hex_symbol(n & 0xf, char_case);
}
