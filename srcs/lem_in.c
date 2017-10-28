/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:47:39 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 17:30:07 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

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
		ret = joinfree(ret, buf, 1);
		buf[0] = '\0';
		read(0, buf, 1);
	}
	free(buf);
	return (ret);
}

t_room		*new_room(char *s, t_room **lst, int start_end)
{
	t_room	*tmp;
	t_room	*new;
	int		i;

	if (!s)
		return (NULL);
	new = malloc(sizeof(t_room));
	i = 0;
	while (s[i] && ft_isalphanum(s[i]))
		i++;
	new->name = ft_strsub_free(s, 0, i, 0);
	new->start_end = start_end;
	new->ant = 0;
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
	return (*lst);
}

void		new_link(char *s, t_room **lst)
{
	char	**linked;
	t_room	*tmp1;
	t_room	*tmp2;

	linked = ft_strsplit(s, '-');
	tmp1 = get_room(*lst, linked[0]);
	tmp2 = get_room(*lst, linked[1]);
	new_room(linked[1], &(tmp1->link), tmp2->start_end);
	new_room(linked[0], &(tmp2->link), tmp1->start_end);
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
	if (rooms)
		get_start(rooms, input, ft_atoi(input[0]));
	else
		write(1, "ERROR\n", 6);
	free_tab(input);
	free_lst(rooms);
	return(0);
}
