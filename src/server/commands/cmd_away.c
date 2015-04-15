/*
** cmd_away.c for myirc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 23:22:22 2015 Girardot Nicolas
** Last update Mon Apr 13 20:34:28 2015 Serge Heitzler
*/

#include "server.h"

int	cmd_away(t_server *server, t_user *user, const char *cmd)
{
  cmd = cmd;
  (void) server;
  if (user->status == CONNECTED)
    {
      user->status = AWAY;
      send_data(user->fd, COLOR_YELLOW
		"[SERVER-INFO] : You are now AWAY\n" COLOR_RESET);
      printf(COLOR_YELLOW "[%s] is now AWAY\n" COLOR_RESET, user->nickname);
    }
  else
    {
      user->status = CONNECTED;
      send_data(user->fd, COLOR_GREEN
		"[SERVER-INFO] : You are now CONNECTED\n" COLOR_RESET);
      printf(COLOR_GREEN "[%s] is now CONNECTED\n" COLOR_RESET, user->nickname);
    }
  return (SUCCESS);
}
