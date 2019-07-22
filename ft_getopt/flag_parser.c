/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:39:37 by maks              #+#    #+#             */
/*   Updated: 2019/07/22 19:10:08 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static int is_flag_valid(int flag, const char *opt_str)
{
	return FT_BOOL((int)ft_strchr(opt_str, flag));
}

static int flag_has_argument(int flag, const char *opt_str)
{
	return ft_strchr(opt_str, flag) && *(ft_strchr(opt_str, flag) + 1) == ':'; 
}

static int is_multi_symbol(const char *flag_string)
{
	return FT_BOOL(ft_strlen(flag_string + 2));
}

static int is_last_symbol(const char *flag_str)
{
	return (flag_str[g_flag_position + 1] == '\0');
}

int g_flag_position;

int get_flag_symbol(char *const flag_str)
{
	g_flag_position++;
	return flag_str[g_flag_position];	
}

t_flag *parse_flag(int argc __unused, char *const flag_str, const char *opt_str)
{
	t_flag *flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	ft_bzero(flag, sizeof(t_flag));


	flag->symbol = get_flag_symbol(flag_str);
	flag->is_multi_symbol = is_multi_symbol(flag_str);
	flag->valid = is_flag_valid(flag->symbol, opt_str);
	flag->has_arg = flag_has_argument(flag->symbol, opt_str);
	flag->str = flag_str;
	flag->is_last_symbol = is_last_symbol(flag_str);

	return flag;
}