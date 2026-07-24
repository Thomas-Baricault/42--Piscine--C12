/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:02:04 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/12 09:43:36 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*ptr;

	if (*begin_list == NULL)
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		ptr = (*begin_list)->next;
		free_fct((*begin_list)->data);
		free(*begin_list);
		*begin_list = ptr;
		ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
	}
	else
		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp, free_fct);
	return ;
}
