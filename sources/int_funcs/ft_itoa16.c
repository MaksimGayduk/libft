/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:46:40 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:44:31 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_prefix(char *str)
{
	str[0] = '0';
	str[1] = 'x';
}

char		*ft_itoa16(uintmax_t n, t_bool char_case, t_bool prefix)
{
	intmax_t	num;
	char		temp;
	size_t		len;
	char		*str;

	num = n;
	len = prefix ? (ft_numlen_base(n, 16) + 2) : ft_numlen_base(n, 16);
	str = ft_strnew(len);
	if (n == 0)
		str[0] = '0';
	len--;
	while (num)
	{
		temp = FT_ABS(num % 16);
		if (temp <= 9)
			str[len] = temp + '0';
		else
			str[len] = temp - 10 + (char_case == 1 ? 'A' : 'a');
		num /= 16;
		len--;
	}
	prefix ? set_prefix(str) : NULL;
	return (str);
}
