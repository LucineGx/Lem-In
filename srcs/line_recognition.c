/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_recognition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:57:46 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 19:33:14 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room	*get_room(t_room *lst, char *s)
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
	if (!get_room(lst, cut_string[0]))
		ret = 0;
	if (!get_room(lst, cut_string[1]))
		ret = 0;
	if (cut_string[2])
		ret = 0;
	free_tab(cut_string);
	return (ret);
}

int		is_room_ok(char *s, t_room *lst)
{
	char	**cut;
	int		i;

	cut = ft_strsplit(s, ' ');
	if (get_room(lst, cut[0]) || !cut[1])
		return (free_tab(cut));
	i = -1;
	while (cut[1][++i])
		if (!(ft_isdigit(cut[1][i]) || (cut[1][i] == '-' && i == 0)))
			return (free_tab(cut));
	i = -1;
	if (!cut[2])
		return (free_tab(cut));
	while (cut[2][++i])
		if (!(ft_isdigit(cut[2][i]) || (cut[2][i] == '-' && i == 0)))
			return (free_tab(cut));
	if (cut[3])
		return (free_tab(cut));
	if (cut[0][0] == 'L' || ft_strchr(cut[0], '-'))
		return (free_tab(cut));
	free_tab(cut);
	return (1);
}

int		get_line_job(char *s, t_room *lst)
{
	int	i;

	if (!s)
		return (0);
	if (ft_atoi(s))
	{
		i = 0;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (!s[i])
			return (1);
	}
	if (!ft_strcmp(s, "##start"))
		return (5);
	if (!ft_strcmp(s, "##end"))
		return (6);
	if (s[0] == '#' && s[1] == '#')
		return (7);
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
	int	ants;

	i = -1;
	start_end = 0;
	ants = 0;
	while (tab[++i])
	{
		j = get_line_job(tab[i], lst);
		ants = (j == 1 && i == 0) ? ft_atoi(tab[i]) : ants;
		start_end = (j == 5) ? 1 : start_end;
		start_end = (j == 6) ? 2 : start_end;
		if (j == 3)
		{
			new_room(tab[i], &lst, start_end);
			start_end = 0;
		}
		if (j == 4)
			new_link(tab[i], &lst);
		if (j == 0 || ants <= 0)
			return (lst);
	}
	return (lst);
}
