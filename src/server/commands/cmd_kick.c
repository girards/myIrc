/*
** cmd_kick.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Mon Apr 13 19:19:34 2015 Serge Heitzler
** Last update Mon Apr 13 20:33:58 2015 Serge Heitzler
*/

#include "server.h"

void		show_kick(t_server *server, t_user *user, char *kicked)
{
  t_user	*user_k;
  char		*msgfinal;
  char		*prvkick;

  user_k = get_user_in_list(server->users, kicked);
  msgfinal = xmalloc(sizeof(char) *
		     (strlen(kicked) + strlen(user->nickname) + 30));
  memset(msgfinal, 0, strlen(kicked) + strlen(user->nickname) + 30);
  sprintf(msgfinal, COLOR_RED "%s has just kicked %s\n"
	  COLOR_RESET, user->nickname, kicked);
  send_msg_to_channel(server, user, msgfinal);
  printf(COLOR_BLUE "[%s] has kicked [%s] from [%s]\n"
	 COLOR_RESET, user->nickname, kicked, user->channel_name);
  prvkick = xmalloc(sizeof(char) *
		     (strlen(kicked) + strlen(user->nickname) + 50));
  memset(prvkick, 0, strlen(kicked) + strlen(user->nickname) + 50);
  sprintf(prvkick, COLOR_RED "%s just kicked you from %s\n"
	  COLOR_RESET, user->nickname, user->channel_name);
  send_data(user_k->fd, prvkick);
}

int		cmd_kick(t_server *server, t_user *user, const char *command)
{
  t_channel	*channel;
  char	        kicked[30];
  char		cmd[50];

  channel = get_channel_in_list(server->channels, user->channel_name);
  sscanf(command, "%s %s", cmd, kicked);
  if ((strcmp(user->nickname, channel->operator)) == 0)
    kick_user_from_channel(server, kicked, user->channel_name);
  else
    {
      printf(COLOR_BLUE "%s has kicked %s w/out op's right\n"
	     COLOR_RESET, user->nickname, kicked);
      send_data(user->fd, COLOR_RED "You are not operator\n" COLOR_RESET);
      return (ERROR);
    }
  show_kick(server, user, kicked);
  return (SUCCESS);
}
