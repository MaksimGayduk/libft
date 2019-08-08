/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:46:47 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/08 19:08:01 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_m(char *s1, char *s2, int mode)
{
    char *joined;

    joined = ft_strjoin(s1, s2);
    if (mode == FT_FREE_FIRST || mode == FT_FREE_BOTH)
    {
        free(s1);
    }
    if (mode == FT_FREE_SECOND || mode == FT_FREE_BOTH)
    {
        free(s2);
    }
    return (joined);
}