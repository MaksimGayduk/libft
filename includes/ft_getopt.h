/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:59:03 by maks              #+#    #+#             */
/*   Updated: 2019/07/22 19:06:36 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

typedef struct		s_flag
{
	int				symbol;
	int				valid;
	int				is_last_symbol;
	char			*str;
	int				is_multi_symbol;
	int				has_arg;
}					t_flag;

extern int g_flag_position;

int ft_getopt(int argc, char *const argv[], const char *opt_string);
t_flag *parse_flag(int argc __unused, char *const flag_str, const char *opt_str);

#endif
