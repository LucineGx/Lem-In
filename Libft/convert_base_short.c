/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:15:59 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/17 19:55:36 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_char_sh(unsigned short n, int base)
{
	int i;

	i = 1;
	while (n / base > 0)
	{
		n /= base;
		i += 1;
	}
	return (i);
}

char		*convert_base_short(unsigned short *n, char opt)
{
	char			*base_str;
	char			*ret;
	int				i;

	base_str = create_base(opt);
	i = count_char_sh(*n, ft_strlen(base_str));
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = '\0';
	while (--i >= 0)
	{
		ret[i] = base_str[*n % ft_strlen(base_str)];
		*n /= ft_strlen(base_str);
	}
	free(base_str);
	base_str = NULL;
	return (ret);
}
