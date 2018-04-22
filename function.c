/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:47:25 by apyltsov          #+#    #+#             */
/*   Updated: 2018/04/18 19:47:29 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_createlist(t_lst **list, char *content)
{
	t_lst	*time;
	t_lst	*elem;

	time = *list;
	elem = (t_lst *)ft_memalloc(sizeof(t_lst));
	elem->cont = content;
	elem->next = NULL;
	if (time == NULL)
		*list = elem;
	else
	{
		while (time->next)
			time = time->next;
		time->next = elem;
	}
}
