/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:26:26 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/09 14:07:30 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*elem;
	t_list	**ptr;

	while (begin_list2)
	{
		elem = begin_list2;
		begin_list2 = begin_list2->next;
		ptr = begin_list;
		while (*ptr && (*cmp)(elem->data, (*ptr)->data) > 0)
			ptr = &(*ptr)->next;
		if (*ptr)
			elem->next = *ptr;
		*ptr = elem;
	}
	return ;
}
