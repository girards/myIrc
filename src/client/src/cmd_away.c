/*
** cmd_away.c for myirc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 23:22:22 2015 Girardot Nicolas
** Last update Mon Apr 13 21:52:24 2015 Serge Heitzler
*/

#include "client.h"

int	cmd_away(t_client *user, const char *cmd)
{
  cmd = cmd;
  send_data(user->cli_info.socket, "AWAY\n");
  return (0);
}
