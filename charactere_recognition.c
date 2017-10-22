/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:01:51 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/22 17:45:17 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_isalphanum(char c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

int		ft_iswhitespace(char c)
{
	if (c == '\n')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}
