/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:34:10 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/27 19:18:16 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		move(char *room_name, char ***ants, int n, int ants_nb)
{
	if (!n)
	{
		while (n < ants_nb)
			(*ants)[n++] = ft_strdup(room_name);
		(*ants)[n] = NULL;
	}
	else
	{
		free((*ants)[n]);
		(*ants)[n] = ft_strdup(room_name);
	}
}

void		solve_lem_in(t_room *path, int nb)
{
	 char		**ant;
	 t_room		*last;
	 int		i;

	 last = path;
	 while (last->next != NULL)
		 last = last->next;
	 if (!(ant = malloc(sizeof(char*) * (nb + 1))))
		 return ;
	 move(path->name, &(ant), 0, nb);
	 while (ft_strcmp(ant[nb - 1], last->name))
	 {
		 i = 0;
		 write(1, "\n", 1);
		 while(ant[i])
		 {
			 if (ft_strcmp(ant[i], last->name))
			 {
				 move(((get_room(path, ant[i]))->next)->name, &(ant), i, nb);
				 ft_printf("L%d-%s ", i + 1, ant[i]);
				 if (ant[i + 1] && ft_strcmp(ant[i],
							 ((get_room(path, ant[i + 1]))->next)->name))
					 i = nb - 1;
			 }
			 i++;
		 }
	 }
	 free_tab(ant);
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
	}
	else
		write(1, "ERROR\n", 6);
}
