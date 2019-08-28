/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:02:52 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:47:38 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DL_LIST_H
# define FT_DL_LIST_H

# include "libft.h"

typedef struct		s_dl_list
{
	void			*content;
	size_t			content_size;
	struct s_btree	*prev;
	struct s_btree	*next;
}					t_dl_list;

t_dl_list			*ft_dl_list_new(void const *content, size_t content_size);

#endif
