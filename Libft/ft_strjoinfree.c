/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:54:32 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 16:01:41 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*joinfree(char *s1, char *s2, int f)
{
	char *ret;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		ret = (s1 == NULL) ? ft_strdup(s2) : ft_strdup(s1);
	else
	{
		if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
	}
	if (s1 && (f == 1 || f == 3))
		free(s1);
	if (s2 && (f == 2 || f == 3))
		free(s2);
	return (ret);
}
