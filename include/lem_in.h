/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:52:25 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/28 20:06:07 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct	s_room
{
	char			*name;
	int				start_end;
	int				ant;
	struct s_room	*link;
	struct s_room	*next;
}				t_room;

t_room			*manage_input(char **input, t_room *lst);
t_room			*new_room(char *s, t_room **lst, int start_end);
void			new_link(char *s, t_room **lst);
t_room			*get_room(t_room *lst, char *s);
int				free_tab(char **tab);
void			free_lst(t_room *lst);
char			**add_line_to_tab(char **tab);
void			remove_last_room(t_room **lst);
void			get_start(t_room *lst, char **input, int ants);
void			display_tab(char **tab);
void			solve_lem_in(t_room *path, int ants_nb);

#endif
