/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:32:48 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/27 16:01:55 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, int start, int len)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i - start < len)
	{
		ret[i - start] = s[i];
		i++;
	}
	ret[i - start] = '\0';
	return (ret);
}

char	*ft_strsub_free(char *s, int start, int len, int y_free)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i - start < len)
	{
		ret[i - start] = s[i];
		i++;
	}
	ret[i - start] = '\0';
	if (y_free)
		free(s);
	return (ret);
}
