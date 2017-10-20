/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:47:39 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/20 17:35:47 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*simple_gnl_from_si(void)
{
	char *buf;
	char *ret;

	ret = NULL;
	if (!(buf = malloc(sizeof(char) * 2)))
		return (NULL);
	buf[0] = '\0';
	buf[1] = '\0';
	read(0, buf, 1);
	while (buf && buf[0] != '\n')
	{
		ret = ft_strjoinfree(ret, buf, 1);
		read(0, buf, 1);
	}
	free(buf);
	return (ret);
}
