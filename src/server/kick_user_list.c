/*
** kick_user_list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue Apr  7 18:20:47 2015 Serge Heitzler
** Last update Mon Apr 13 20:35:45 2015 Serge Heitzler
*/

#include "server.h"

t_node		*get_node_user(t_server *server, char *nickname)
{
  t_user	*tmp_u;
  t_node	*tmp;

  tmp = server->users->start;
  while (tmp)
    {
      tmp_u = get_user_in_list(server->users, nickname);
      if ((strcmp(tmp_u->nickname, nickname)) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		kick_user_from_channel(t_server *server,
				       char *nickname, char *channel_name)
{
  delete_channel_in_user(server->users, nickname);
  delete_user_in_channel(server->channels, nickname, channel_name);
  return (SUCCESS);
}

int		kick_user_from_server(t_server *server, char *nickname)
{
  t_user	*user;

  user = get_user_in_list(server->users, nickname);
  kick_user_from_channel(server, user->nickname, user->channel_name);
  close(user->fd);
  delete_node(server->users, get_node_user(server, nickname));
  return (SUCCESS);
}
