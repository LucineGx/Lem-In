/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:52:25 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/22 19:22:15 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_room
{
	char			*name;
	struct s_room	*link;
	struct s_room	*next;
}				t_room;

t_room			*manage_input(char **input, t_room *lst);
void			new_room(char *s, t_room **lst);
void			new_link(char *s, t_room **lst);
t_room			*is_room_name(t_room *lst, char *s);
void			free_tab(char **tab);
char			**add_line_to_tab(char **tab);

#endif
