/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:15:59 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/27 15:50:01 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*create_base(char opt)
{
	if (opt == 'o')
		return (ft_strdup("01234567"));
	if (opt == 'x')
		return (ft_strdup("0123456789abcdef"));
	if (opt == 'X')
		return (ft_strdup("0123456789ABCDEF"));
	if (opt == 'u')
		return (ft_strdup("0123456789"));
	return (NULL);
}

int		count_char(unsigned int n, int base)
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

char	*convert_base(unsigned int *n, char opt)
{
	char			*base_str;
	char			*ret;
	int				i;

	base_str = create_base(opt);
	i = count_char(*n, ft_strlen(base_str));
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

int		satoi(const char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i += 1;
	}
	return (nb);
}
