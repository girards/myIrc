/*
** cmd_privmsg.c for myirc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 21:02:29 2015 Girardot Nicolas
** Last update Mon Apr 13 20:19:30 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_privmsg(t_client *user, const char *command)
{
  char			cmd[50];
  char			to[50];
  char			msg[4096];
  char			*cmd_final;

  sscanf(command, "%s %s %4050[^\n]", cmd, to, msg);
  cmd_final = malloc(strlen("PRIVMSG") + strlen(to) + strlen(msg) + 2);
  sprintf(cmd_final, "PRIVMSG %s %s", to, msg);
  send_data(user->cli_info.socket, cmd_final);
  return (SUCCESS);
}
