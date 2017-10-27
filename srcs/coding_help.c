#include "../include/lem_in.h"
#include <stdio.h>

void		display_rooms(t_room *lst)
{
	t_room *link;

	printf("SALLES:\n");
	while (lst != NULL)
	{
		if (lst->start_end)
			printf((lst->start_end == 1) ? "start:" : "end:");
		printf("\t%s\n", lst->name);
		link = lst->link;
		printf("\t\tLINK:\n");
		while (link != NULL)
		{
			printf("\t\t\t%s\n", link->name);
			link = link->next;
		}
		lst = lst->next;
	}
}

void		display_path(t_room *lst)
{
	printf("START\n");
	while (lst)
	{
		printf("\t%s\n", lst->name);
		lst = lst->next;
	}
	printf("END\n");
}
