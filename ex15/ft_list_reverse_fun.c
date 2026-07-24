/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:58:46 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/08 15:25:15 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_reverse_single(t_list *begin_list, int size)
{
	t_list	*ptr;
	void	*tmp;

	ptr = begin_list;
	while (--size > 0)
		ptr = ptr->next;
	tmp = begin_list->data;
	begin_list->data = ptr->data;
	ptr->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*ptr;
	int		size;

	ptr = begin_list;
	size = 0;
	while (ptr)
	{
		ptr = ptr->next;
		size++;
	}
	while (size > 0)
	{
		ft_reverse_single(begin_list, size);
		begin_list = begin_list->next;
		size -= 2;
	}
	return ;
}
