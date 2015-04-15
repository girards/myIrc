/*
** user_list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu Apr  2 15:59:59 2015 Serge Heitzler
** Last update Mon Apr 13 21:54:12 2015 Serge Heitzler
*/

#include "server.h"

int		is_operator_in_channel(t_server *server,
				       char *nickname, char *channel_name)
{
  t_user	*user;

  user = get_user_in_list(server->users, nickname);
  if ((strcmp(user->channel_name, channel_name)) == 0
      && (user->right == OPERATOR))
    return (YES);
  else
    return (NO);
}

int		is_user_in_channel(t_server *server, char *nickname, char *channel_name)
{
  t_user	*user;

  user = get_user_in_list(server->users, nickname);
  if ((strcmp(user->channel_name, channel_name)) == 0)
    return (YES);
  else
    return (NO);
}

int		is_user_existing(t_server *server, char *nickname)
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
	return (YES);
    }
  return (NO);
}

int		show_users_in_channel(t_server *server, char *channel_name, int fd)
{
  t_node	*tmpd;
  t_channel	*channel;
  t_user	*user;
  char		*final;

  channel = get_channel_in_list(server->channels, channel_name);
  tmpd = channel->user_connected->start;
  send_data(fd, "@");
  while (tmpd)
    {
      user = get_user_in_list(server->users, (char*)tmpd->data);
      final = xmalloc(strlen((char*)tmpd->data) + 1);
      memset(final, 0, strlen((char*)tmpd->data) + 1);
      if (user->status == CONNECTED)
	sprintf(final, COLOR_GREEN "%s\n" COLOR_RESET, (char*)tmpd->data);
      else
	sprintf(final, COLOR_YELLOW "%s\n" COLOR_RESET, (char*)tmpd->data);
      send_data(fd, final);
      tmpd = tmpd->next;
      free(final);
    }
  return (SUCCESS);
}
