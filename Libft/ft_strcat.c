/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:10:22 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/20 17:12:29 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	id;
	int	is;

	if (!dest || !src)
		return (dest);
	id = 0;
	is = 0;
	while (dest[id])
		id++;
	while (src[is])
		dest[id++] = src[is++];
	dest[id] = '\0';
	return (dest);
}
