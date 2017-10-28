/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:22:59 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 18:07:48 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return ((!s1) ? s2[i] : s1[i]);
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (!(s1[i]))
		return(0);
	else
		return (s1[i] - s2[i]);
}

int		ft_strncmp(char *s1, char *s2, int n)
{
	if (ft_strlen(s1) < n || ft_strlen(s2) < n)
		return (ft_strcmp(s1, s2));
	else
		return (ft_strcmp(ft_strsub(s1, 0, n), ft_strsub(s2, 0, n)));
}
