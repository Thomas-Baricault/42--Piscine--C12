/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:52:01 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/08 09:52:01 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin;
	t_list	*new;

	begin = NULL;
	while (size-- > 0)
	{
		new = ft_create_elem((void *)*strs++);
		new->next = begin;
		begin = new;
	}
	return (begin);
}
