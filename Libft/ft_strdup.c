/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:41:16 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 16:05:14 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(char *s)
{
	char *ret;

	if (!s)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(ret, s));
}

char	*ft_strdup_void(void *s, t_convlst *opt)
{
	char	**tmp;
	char	*src;
	char	*dest;
	int		i;

	(void)opt;
	tmp = (char**)s;
	src = *tmp;
	if (!src)
		return (NULL);
	if ((dest = malloc(sizeof(char) * ft_strlen(src) + 1)) == 0)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
