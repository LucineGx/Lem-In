/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:04:17 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 18:23:28 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		free_tab(char **tab)
{
	int i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (0);
}

char	**add_line_to_tab(char **tab)
{
	char	**new_tab;
	int		i;

	if (!tab)
	{
		new_tab = malloc(sizeof(char*));
		*new_tab = NULL;
		return (new_tab);
	}
	i = 0;
	while (tab[i])
		i++;
	if (!(new_tab = malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = -1;
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i] = NULL;
	new_tab[i + 1] = NULL;
	free_tab(tab);
	return (new_tab);
}

void	display_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	free_lst(t_room *lst)
{
	if (lst)
	{
		if (lst->next)
			free_lst(lst->next);
		if (lst->link)
			free_lst(lst->link);
		free(lst->name);
		lst->name = NULL;
		free(lst);
		lst = NULL;
	}
}

void	remove_last_room(t_room **lst)
{
	t_room	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while ((tmp->next)->next != NULL)
		tmp = tmp->next;
	free_lst(tmp->next);
	tmp->next = NULL;
}
