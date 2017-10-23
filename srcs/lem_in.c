/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:47:39 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/23 20:05:01 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*simple_gnl_from_si(void)
{
	char	*buf;
	char	*ret;

	if (!(buf = malloc(sizeof(char) * 2)))
		return (NULL);
	buf[0] = '\0';
	buf[1] = '\0';
	read(0, buf, 1);
	ret = NULL;
	while (buf[0] && buf[0] != '\n')
	{
		ret = ft_strjoinfree(ret, buf, 1);
		buf[0] = '\0';
		read(0, buf, 1);
	}
	free(buf);
	return (ret);
}

void		new_room(char *s, t_room **lst, int start_end)
{
	t_room	*tmp;
	t_room	*new;
	int		i;

	if (!s)
		return;
	new = malloc(sizeof(t_room));
	i = 0;
	while (s[i] && ft_isalphanum(s[i]))
		i++;
	new->name = ft_strsub(s, 0, i);
	new->start_end = start_end;
	new->link = NULL;
	new->next = NULL;
	tmp = *lst;
	if (!tmp)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		new_link(char *s, t_room **lst)
{
	char	**linked;
	t_room	*tmp;

	linked = ft_strsplit(s, '-');
	tmp = is_room_name(*lst, linked[0]);
	new_room(linked[1], &(tmp->link), 0);
	tmp = is_room_name(*lst, linked[1]);
	new_room(linked[0], &(tmp->link), 0);
	free_tab(linked);
}

int			main(void)
{
	char	**input;
	char	*tmp;
	int		i;
	t_room	*rooms;

	if (!(input = malloc(sizeof(char*))))
		return (0);
	input[0] = NULL;
	i = 0;
	while ((tmp = simple_gnl_from_si()))
	{
		input = add_line_to_tab(input);
		input[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	rooms = NULL;
	rooms = manage_input(input, rooms);
	display_tab(input);
	free_tab(input);
	display_rooms(rooms);//
	free_lst(rooms);
	return(0);
}