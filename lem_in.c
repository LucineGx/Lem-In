/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:47:39 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/22 19:22:11 by lgaveria         ###   ########.fr       */
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
	while (buf && buf[0] != '\n')
	{
		ret = ft_strjoinfree(ret, buf, 1);
		read(0, buf, 1);
	}
	free(buf);
	return (ret);
}

void		new_room(char *s, t_room **lst)
{
	t_room	*tmp;
	t_room	*new;
	int		i;

	new = malloc(sizeof(t_room));
	i = 0;
	while (ft_isalphanum(s[i]))
		i++;
	new->name = ft_strsub(s, 0, i);
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
	char	**link;
	t_room	*tmp;

	linked = ft_strplit(s, '-');
	tmp = is_room_name(*lst, linked[0]);


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
		input[i] = tmp;
		i++;
	}
	rooms = NULL;
	rooms = manage_input(input, rooms);
	return(0);
}
