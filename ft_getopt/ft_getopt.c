/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:43:54 by maks              #+#    #+#             */
/*   Updated: 2019/07/22 18:52:45 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void print_flag(t_flag *flag)
{
	ft_printf("Flag info:\n");
	ft_printf("\tsymbol: %c\n", flag->symbol);
	ft_printf("\tvalid: %i\n", flag->valid);
	ft_printf("\tis last symbol: %i\n", flag->is_last_symbol);
	ft_printf("\tstring: %s\n", flag->str);
	ft_printf("\tis multi symbol: %i\n", flag->is_multi_symbol);
	ft_printf("\thas arguments: %i\n", flag->has_arg);
}

int is_flag(char *const str)
{
	return str != NULL && str[0] == '-' && str[1] != '\0';
}

void check_optarg(t_flag *flag, const char *opt_str)
{
	if (optarg == NULL)
	{
		flag->symbol = opt_str[0] == ':' ? ':' : '?';
	}
}

void set_global_vars()
{
	optind++;
	g_flag_position = 0;
}

void process_multi_flag(t_flag *flag, char *const *argv, const char *opt_str)
{
	optopt = flag->symbol;
	
	if (flag->has_arg)
	{
		optarg = flag->is_last_symbol ? argv[++optind] : ft_strchr(argv[optind], flag->symbol) + 1;
		check_optarg(flag, opt_str);
		set_global_vars();
	}
	else if (flag->is_last_symbol)
	{
		set_global_vars();
	}
}

void process_single_flag(t_flag *flag, char *const *argv, const char *opt_str)
{
	optopt = flag->symbol;

	if (flag->has_arg)
	{
		optarg = argv[++optind];
		check_optarg(flag, opt_str);
	}
	set_global_vars();
}

int	ft_getopt(int argc __unused, char *const *argv, const char *opt_str)
{
	t_flag *flag;

	if  (!is_flag(argv[optind])) {
		return (-1);
	}
	flag = parse_flag(argc, argv[optind], opt_str);

	print_flag(flag);

	if (!flag->valid)
	{
		optopt = flag->symbol;
		optind++;
		return '?';
	}

	flag->is_multi_symbol ? process_multi_flag(flag, argv, opt_str) : process_single_flag(flag, argv, opt_str);
	
	return (flag->symbol);
}
