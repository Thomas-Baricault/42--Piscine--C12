/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:14:16 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/08 14:57:15 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*tmp;

	if (*begin_list == NULL)
		return ;
	ft_list_sort(&(*begin_list)->next, cmp);
	ptr = *begin_list;
	while (ptr->next && (*cmp)((*begin_list)->data, ptr->next->data) > 0)
		ptr = ptr->next;
	if (ptr != *begin_list)
	{
		tmp = ptr->next;
		ptr->next = *begin_list;
		ptr = (*begin_list)->next;
		(*begin_list)->next = tmp;
		*begin_list = ptr;
	}
	return ;
}
