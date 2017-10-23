/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_recognition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:57:46 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/23 20:05:04 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*is_room_name(t_room *lst, char *s)
{
	if (!lst || !s)
		return (NULL);
	while (lst)
	{
		if (ft_strcmp(s, lst->name) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int		is_link_ok(char *s, t_room *lst)
{
	char	**cut_string;
	int		ret;

	cut_string = ft_strsplit(s, '-');
	ret = 1;
	if (!is_room_name(lst, cut_string[0]))
		ret = 0;
	if (!is_room_name(lst, cut_string[1]))
		ret = 0;
	if (cut_string[2])
		ret = 0;
	free_tab(cut_string);
	return (ret);
}

int		is_room_ok(char *s, t_room *lst)
{
	char	**cut_string;
	int		i;

	cut_string = ft_strsplit(s, ' ');
	if (is_room_name(lst, cut_string[0]) || !cut_string[1])
		return (free_tab(cut_string));
	i = -1;
	while (cut_string[1][++i])
		if (!ft_isdigit(cut_string[1][i]))
			return (free_tab(cut_string));
	i = -1;
	if (!cut_string[2])
		return (free_tab(cut_string));
	while (cut_string[2][++i])
		if (!ft_isdigit(cut_string[2][i]))
			return (free_tab(cut_string));
	if (cut_string[3])
		return (free_tab(cut_string));
	free_tab(cut_string);
	return (1);
}

int		get_line_job(char *s, t_room *lst)
{
	if (!s)
		return (0);
	if (s[0] == '#' && s[1] == '#')
		return (1);
	if (s[0] == '#' && s[1] != '#')
		return (2);
	if (is_room_ok(s, lst))
		return (3);
	if (is_link_ok(s, lst))
		return (4);
	return (0);
}

t_room	*manage_input(char **tab, t_room *lst)
{
	int	i;
	int	j;
	int	start_end;

	i = 0;
	start_end = 0;
	while (tab[i])
	{
		j = get_line_job(tab[i], lst);
		if (j == 1)
		{
			start_end = (!ft_strncmp(tab[i], "##start\0", 8)) ? 1 : start_end;
			start_end = (!ft_strncmp(tab[i], "##end\0", 6)) ? 2 : start_end;
		}
		if (j == 3)
		{
			new_room(tab[i], &lst, start_end);
			start_end = 0;
		}
		if (j == 4)
			new_link(tab[i], &lst);
		if (j == 0)
			return (lst);
		i++;
	}
	return (lst);
}
