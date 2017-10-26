/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:34:10 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/26 20:07:51 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		solve_lem_in(t_room *path)
{
	display_path(path);
}

t_room		*get_path(t_room *full, t_room *lst, t_room *path)
{
	t_room *tmp;

	tmp = lst;
	while (tmp && tmp->start_end != 2)
		tmp = tmp->next;
	if (tmp)
		return (new_room(tmp->name, &(path), 2));
	while (lst)
	{
		if (!(get_room(path, lst->name)))
		{
			new_room(lst->name, &(path), lst->start_end);
			if ((tmp = get_path(full, (get_room(full, lst->name))->link, path)))
				return (tmp);
			remove_last_room(&(path));
		}
		lst = lst->next;
	}
	return (NULL);
}

void		get_start(t_room *lst, char **input, int ants)
{
	t_room	*tmp;
	t_room	*path;

	path = NULL;
	tmp = lst;
	while (tmp->start_end != 2)
		tmp = tmp->next;
	tmp = lst;
	while (tmp && tmp->start_end != 1)
		tmp = tmp->next;
	if (tmp)
		path = get_path(lst, tmp->link, new_room(tmp->name, &(path), 1));
	if (path && ants)
	{
		display_tab(input);
		solve_lem_in(path);
	}
	else
		write(1, "ERROR\n", 6);
}
