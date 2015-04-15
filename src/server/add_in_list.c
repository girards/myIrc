/*
** add_in_list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue Apr  7 21:58:16 2015 Serge Heitzler
** Last update Mon Apr 13 20:36:01 2015 Serge Heitzler
*/

#include "server.h"

void		add_node(t_list *list, t_node *node)
{
  if (list != NULL)
    {
      if (list->start == NULL)
	{
	  list->start = node;
	  list->end = node;
	  node->next = NULL;
	  node->prev = NULL;
	}
      else
	{
	  list->end->next = node;
	  node->prev = list->end;
	  node->next = NULL;
	  list->end = node;
	}
      list->length++;
    }
}

void		push_in_list(t_list *list, void *data)
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->data = data;
  add_node(list, node);
}
