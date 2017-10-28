/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:34:10 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 18:08:24 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		**move(t_room *path, t_room **ants, int n, int ants_nb)
{
	int		i;

	i = 0;
	if (n == -1)
	{
		while (i < ants_nb)
			ants[i++] = path;
		ants[i] = NULL;
	}
	else
		ants[n] = (ants[n])->next;
	return (ants);
}

void		solve_lem_in(t_room *path, int nb)
{
	t_room	**ants;
	int		i;

	if (!(ants = malloc(sizeof(t_room*) * nb)))
		return ;
	ants = move(path, ants, -1, nb);
	while ((ants[nb - 1])->next != NULL)
	{
		i = 0;
		write(1, "\n", 1);
		while (i < nb)
		{
			if ((ants[i])->next != NULL)
			{
				ants = move(path, ants, i, nb);
				printf("L%d-%s ", i + 1, (ants[i])->name);
				if (!(ft_strcmp((ants[i])->name, (path->next)->name)))
					i = nb - 1;
			}
			i++;
		}
	}
	free(ants);
}

t_room		*get_path(t_room *full, t_room *lst, t_room *path)
{
	t_room *tmp;

	tmp = lst;
	while (tmp && tmp->start_end != 2)
		tmp = tmp->next;
	if (tmp)
		return (new_room(tmp->name, &(path), 2));
	while (lst && lst->name)
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
	while (tmp && tmp->start_end != 1)
		tmp = tmp->next;
	if (tmp)
		path = get_path(lst, tmp->link, new_room(tmp->name, &(path), 1));
	if (path && ants)
	{
		display_tab(input);
		solve_lem_in(path, ants);
		free_lst(path);
	}
	else
		write(1, "ERROR\n", 6);
}
