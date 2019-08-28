/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_list_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:09:05 by maks              #+#    #+#             */
/*   Updated: 2019/08/19 17:14:33 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dl_list	*ft_dl_list_new(void const *content, size_t content_size)
{
	t_dl_list *new_node;

	new_node = (t_dl_list *)malloc(sizeof(t_dl_list));
	if (!new_node)
		return (NULL);
	ft_bzero(new_node, sizeof(t_dl_list));
	if (content)
	{
		new_node->content = ft_memalloc(content_size);
		if (!(new_node->content))
		{
			free(new_node);
			return (NULL);
		}
		ft_memcpy(new_node->content, content, content_size);
		new_node->content_size = content_size;
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}