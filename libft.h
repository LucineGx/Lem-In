/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:00:24 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/22 17:45:33 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2, int f);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
int		ft_isdigit(char c);
int		ft_isalphanum(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strsub(char *s, int start, int len);
char	**ft_strsplit(char *s, char c);
int		ft_iswhitespace(char c);
int		ft_atoi(char *str);

#endif
