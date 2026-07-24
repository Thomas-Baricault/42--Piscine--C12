/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:26:26 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/09 14:03:11 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	**ptr;

	ptr = begin_list;
	while (*ptr && (*cmp)(data, (*ptr)->data) > 0)
		ptr = &(*ptr)->next;
	elem = ft_create_elem(data);
	if (*ptr)
		elem->next = *ptr;
	*ptr = elem;
	return ;
}
