/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:04:17 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/22 15:57:34 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_tab(char **tab)
{
	int i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
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
	while(tab[i])
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
