/*
** send_msg_to_channel.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed Apr  8 18:15:36 2015 Serge Heitzler
** Last update Mon Apr 13 21:53:56 2015 Serge Heitzler
*/

#include <sys/time.h>
#include <time.h>
#include "server.h"

char		*format_msg(char *tmbuf, t_user *org_user, const char *msg, char *op)
{
  char		*msgfinal;

  if (strcmp(org_user->nickname, op) != 0)
    {
      msgfinal = xmalloc((strlen(tmbuf) +
			  strlen(org_user->nickname) + strlen(msg) + 9) * sizeof(char));
      memset(msgfinal, 0, (strlen(tmbuf) +
			strlen(org_user->nickname) + strlen(msg) + 9));
      sprintf(msgfinal, "[%s] - %s : %s", tmbuf, org_user->nickname, msg);
    }
  else
    {
      msgfinal = xmalloc((strlen(tmbuf) +
			  strlen(org_user->nickname) + strlen(msg) + 30) * sizeof(char));
      memset(msgfinal, 0, (strlen(tmbuf) +
			strlen(org_user->nickname) + strlen(msg) + 30));
      sprintf(msgfinal, "[%s] - \033[1m\033[37m@%s" COLOR_RESET
	      " : %s", tmbuf, org_user->nickname, msg);
    }
  return (msgfinal);
}

int		send_msg_to_channel(t_server *server, t_user *org_user, const char *msg)
{
  size_t		i;
  char			*name;
  t_user		*user;
  t_channel		*channel;
  char			*msgfinal;
  struct timeval	tv;
  time_t		nowtime;
  struct tm		*nowtm;
  char			tmbuf[64];

  i = 0;
  gettimeofday(&tv, NULL);
  nowtime = tv.tv_sec;
  nowtm = localtime(&nowtime);
  strftime(tmbuf, sizeof(tmbuf), "%H:%M:%S", nowtm);
  channel = get_channel_in_list(server->channels, org_user->channel_name);
  while (i < channel->user_connected->length)
    {
      name = (char*)get_elem_at_pos(channel->user_connected, i++);
      user = get_user_in_list(server->users, name);
      msgfinal = format_msg(tmbuf, org_user, msg, channel->operator);
      send_data(user->fd, msgfinal);
    }
  push_in_list(channel->last_messages, msgfinal);
  return (SUCCESS);
}
