/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:37:58 by lgaveria          #+#    #+#             */
/*   Updated: 2017/08/30 18:45:00 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	countchar(short n)
{
	int	count;

	if (n == -32768)
		return (6);
	if (n == 0 || n == -0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count += 1;
	}
	while (n >= 1)
	{
		count += 1;
		n = n / 10;
	}
	return (count);
}

static char	*putinchar(short n, char *ret, int i)
{
	if (n == -0)
		ret[0] = '0';
	else if (n < 0)
	{
		ret[0] = '-';
		if (n == -32768)
		{
			ret[1] = '3';
			ret = putinchar(2768, ret, i);
		}
		else
			ret = putinchar(-n, ret, i);
	}
	else
	{
		if (n > 9)
			ret = putinchar(n / 10, ret, i - 1);
		ret[i] = (n % 10) + 48;
	}
	return (ret);
}

char		*ft_itoa_short(short *n)
{
	char	*ret;
	int		i;

	i = countchar(*n);
	if ((ret = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	ret[i] = '\0';
	ret = putinchar(*n, ret, i - 1);
	return (ret);
}
