/*
** list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu Apr  2 14:45:22 2015 Serge Heitzler
** Last update Fri Apr 10 10:59:15 2015 Serge Heitzler
*/

#include "server.h"

t_list		*create_list()
{
  t_list	*list;

  list = xmalloc(sizeof(*list));
  if (list != NULL)
    {
      list->length = 0;
      list->start = NULL;
      list->end = NULL;
    }
  return (list);
}

void		free_my_list(t_list *list)
{
  t_node	*tmp;
  t_node	*del;

  tmp = list->start;
  while (tmp)
    {
      del = tmp;
      tmp = tmp->next;
      free(del->data);
      free(del);
    }
  free(list);
}
