/*
** get_in_list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue Apr  7 23:10:18 2015 Serge Heitzler
** Last update Mon Apr 13 20:37:12 2015 Serge Heitzler
*/

#include "server.h"

char		*get_string_in_list(t_list *list, char *request)
{
  size_t       	i;
  t_node	*tmp;
  char		*res;

  i = 0;
  tmp = list->start;
  while (tmp && (strcmp(request, tmp->data) != 0))
    {
      i++;
      tmp = tmp->next;
    }
  res = xmalloc((strlen((char*)tmp->data) + 1) * sizeof(char));
  memset(res, 0, strlen((char*)tmp->data) + 1);
  res = strdup((char*)tmp->data);
  return (res);
}

t_channel	*get_channel_in_list(t_list *channel_list, char *channel_name)
{
  size_t       	i;
  t_node	*tmp;
  t_channel	*channel;

  i = 0;
  tmp = channel_list->start;
  channel = xmalloc(sizeof(t_channel));
  channel = tmp->data;
  while (tmp && (strcmp(channel_name, channel->channel_name) != 0))
    {
      channel = tmp->data;
      tmp = tmp->next;
      i++;
    }
  return (channel);
}

t_user		*get_user_in_list(t_list *user_list, char *nickname)
{
  size_t	i;
  t_node	*tmp;
  t_user	*user;

  i = 0;
  tmp = user_list->start;
  user = xmalloc(sizeof(t_user));
  user = tmp->data;
  while (tmp && (strcmp(nickname, user->nickname) != 0))
    {
      i++;
      user = tmp->data;
      tmp = tmp->next;
    }
  return (user);
}

void		*get_elem_at_pos(t_list *list, size_t pos)
{
  size_t       	i;
  t_node	*tmp;

  i = 0;
  tmp = list->start;
  if (pos > list->length - 1)
    return (NULL);
  while (i < pos)
    {
      tmp = tmp->next;
      i++;
    }
  return (tmp->data);
}

size_t		get_pos_for_elem(t_list *list, t_node *elem)
{
  size_t	i;
  t_node	*tmp;

  i = 0;
  tmp = list->start;
  while (tmp)
    {
      if (tmp == elem)
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (-1);
}
