/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:34:10 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/23 20:04:57 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*get_path(t_room *fullst, t_room *lst, t_room *previous_path)
{
	t_room *tmp;

	tmp = lst;
	while (tmp && tmp->start_end != 2)
		tmp = tmp->next;
	if (tmp->start_end == 2)
		return (new_room(tmp->name, &(previous_path), 2));
	while (lst)
	{
		if (!(is_room_name(previous_path, lst->name)))
		{
			new_room(lst->name, &(previous_path), lst->start_end);
			if (get_path(fullst, (get_room(lst->name, fullst))->link, previous_path)
		}
		linklst = linklst->next;
	}
	if (!linklst)
		return (NULL);
}
