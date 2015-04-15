/*
** cmd_away.c for myirc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 23:22:22 2015 Girardot Nicolas
** Last update Mon Apr 13 20:32:43 2015 Serge Heitzler
*/

#include "server.h"

int	cmd_lock(t_server *server, t_user *user, const char *cmd)
{
  t_channel *channel;

  cmd = cmd;
  channel = get_channel_in_list(server->channels, user->channel_name);
  if (channel->is_private == 0)
    {
      channel->is_private = 1;
      printf(COLOR_BLUE "[%s] has locked channel [%s]\n" COLOR_RESET,
	     user->nickname, channel->channel_name);
      send_msg_to_channel(server, user,
			  COLOR_RED "Channel is locked\n" COLOR_RESET);
    }
  else
    {
      channel->is_private = 0;
      printf(COLOR_BLUE "[%s] has unlocked channel [%s]\n" COLOR_RESET,
	     user->nickname, channel->channel_name);
      send_msg_to_channel(server, user,
			  COLOR_GREEN "Channel is unlocked\n" COLOR_RESET);
    }
  return (SUCCESS);
}
