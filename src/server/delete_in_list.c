/*
** delete_in_list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue Apr  7 21:57:22 2015 Serge Heitzler
** Last update Mon Apr 13 21:07:32 2015 Serge Heitzler
*/

#include "server.h"

void		delete_node(t_list *list, t_node *node)
{
  if (node == list->start)
    {
      if (node->next != NULL)
	list->start = node->next;
      else
	{
	  list->start = NULL;
	  list->end = NULL;
	}
    }
  else if (node == list->end)
    {
      list->end = node->prev;
      list->end->next = NULL;
    }
  else
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
  list->length--;
  free(node);
}

int		delete_channel_in_user(t_list *user_list, char *nickname)
{
  t_user	*user;

  user = get_user_in_list(user_list, nickname);
  user->channel_name = NULL;
  return (SUCCESS);
}

int		delete_user_in_channel(t_list *channel_list,
				       char *nickname, char *channel_name)
{
  size_t	i;
  t_node	*tmpd;
  t_channel	*channel;

  i = 0;
  channel = get_channel_in_list(channel_list, channel_name);
  tmpd = channel->user_connected->start;
  while (tmpd)
    {
      if ((strcmp((char*)tmpd->data, nickname)) != 0)
	tmpd = tmpd->next;
      else
	{
	  delete_node(channel->user_connected, tmpd);
	  tmpd = tmpd->next;
	}
      i++;
    }
  return (SUCCESS);
}

int		delete_user_in_list(t_server *server, char *nickname)
{
  t_node	*tmp;
  t_user	*user;

  tmp = server->users->start;
  while (tmp)
    {
      user = (t_user*)tmp->data;
      if ((strcmp(user->nickname, nickname)) != 0)
	tmp = tmp->next;
      else
	{
	  close(user->fd);
	  delete_user_in_channel(server->channels, nickname, user->channel_name);
	  delete_node(server->users, tmp);
	  return (SUCCESS);
	}
    }
  return (ERROR);
}
