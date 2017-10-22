/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_recogniion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:57:46 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/22 19:22:05 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*is_room_name(t_room *lst, char *s)
{
	if (!lst || !s)
		return (NULL);
	while (lst)
	{
		if (ft_strncmp(s, lst->name, ft_strlen(lst->name) - 1) == 0)
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
	int		ret;

	ret = 0;
	cut_string = ft_strsplit(s, ' ');
	if (is_room_name(lst, cut_string[0]))
		ret = 1;
	i = -1;
	while (cut_string[1] && cut_string[1][++i])
		if (!ft_isdigit(cut_string[1][i]))
			ret = 1;
	i = -1;
	while (cut_string[2] && cut_string[2][++i])
		if (!ft_isdigit(cut_string[2][i]))
			ret = 1;
	if (cut_string[3])
		ret = 1;
	free_tab(cut_string);
	return (ret);
}

int		get_line_job(char *s, t_room *lst)
{
	int i;

	if (!s)
		return (0);
	if (s[0] == '#' && s[1] == '#')
		return (1);
	if (s[0] == '#' && s[1] != '#')
		return (2);
	if (ft_isalphanum(s[0]))
	{
		i = 0;
		while (ft_isalphanum(s[i]))
			i++;
		if (is_room_name(lst, s))
		{
			if (s[i] == '-')
				if (is_room_name(lst, &(s[i + 1])))
					return (3);
		}
		else
			if (is_room_ok(s, lst))
				return (4);
	}
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
			new_room(tab[i], &lst);
		if (j == 4)
			new_link(tab[i], &lst); 
	}
	return (lst);
}
