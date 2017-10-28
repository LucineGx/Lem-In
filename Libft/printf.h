/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:27:58 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 15:59:05 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <limits.h>
# include "libft.h"
# define LCHAR 1
# define LSINT 2
# define LLLINT 3
# define LLINT 4
# define LINTMAXT 5
# define LSIZET 6

typedef struct	s_list
{
	char			*data;
	char			nulchar;
	struct s_list	*next;
}				t_list;

typedef struct	s_arglst
{
	int				n;
	void			*src;
	struct s_arglst	*next;
}				t_arglst;

typedef struct	s_convlst
{
	char				conv;
	char				*str;
	int					opt_len;
	t_arglst			*arg;
	int					i_fw_arg;
	t_arglst			*fw_arg;
	int					fw;
	int					af;
	int					z;
	int					pos;
	int					prec;
	int					lm;
	struct s_convlst	*next;
}				t_convlst;

int				ft_printf(const char *toprint, ...);
t_convlst		*global_pars(char *str);
t_list			*get_str_to_print(char *src, t_convlst *opt);
void			manage_conv(t_convlst **opt);
void			manage_opt(t_convlst **opt);
void			manage_z(t_convlst **o, int z);
char			*manage_int(void *src, t_convlst *opt);
char			*manage_int_to_convert(void *src, t_convlst *opt);
char			*manage_maj_int(void *src, t_convlst *opt);
char			*manage_ptr(void *src, t_convlst *opt);
void			free_convlst(t_convlst *cur);
void			free_arglst(t_arglst *cur);
void			free_list(t_list *cur);
char			*ft_strdup_void(void *s, t_convlst *opt);
int				ft_atoi_base_x(char *s, char b);
char			*ft_itoa_int(int *n);
char			*ft_itoa_char(char *n);
char			*ft_itoa_short(short *n);
char			*ft_itoa_long(long *n);
char			*ft_itoa_sizet(size_t *n);
char			*ft_itoa_intmaxt(intmax_t *n);
char			*ft_itoa_longlong(long long *n);
char			*create_base(char opt);
char			*convert_base(unsigned int *n, char opt);
char			*convert_base_char(unsigned char *n, char opt);
char			*convert_base_short(unsigned short *n, char opt);
char			*convert_base_long(unsigned long *n, char opt);
char			*convert_base_sizet(ssize_t *n, char opt);
char			*convert_base_intmaxt(uintmax_t *n, char opt);
char			*convert_base_longlong(unsigned long long *n, char opt);
char			*ft_putchar_void(void *src, t_convlst *opt);
int				satoi(const char *str);
int				count_char(unsigned int n, int base);

#endif
