/*
** cmd_msg.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed Apr  8 18:15:21 2015 Nicolas Girardot
** Last update Mon Apr 13 20:19:43 2015 Serge Heitzler
*/

#include "server.h"

int	cmd_msg(t_server *server, t_user *user, const char *command)
{
  if ((strcmp(user->nickname, "") == 0) || user->channel_name == NULL)
    {
      printf(COLOR_RED
	     "Somebody tries to speak w/out nickname and channel...\n" COLOR_RESET);
      send_data(user->fd, COLOR_BLUE
		"Set a NICK and JOIN a room\nNICK yourname and JOIN roomname\n" COLOR_RESET);
      return (ERROR);
    }
  if (send_msg_to_channel(server, user, command) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
