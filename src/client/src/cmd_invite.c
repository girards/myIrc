/*
** cmd_invite.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Fri Apr 10 00:24:58 2015 Serge Heitzler
** Last update Mon Apr 13 20:25:03 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_invite(t_client *user, const char *command)
{
  char	        name[29];
  char		cmd[15];
  char		*cmdfinal;

  sscanf(command, "%s %s", cmd, name);
  cmdfinal = malloc(strlen("INVITE") + strlen(name) + 2);
  sprintf(cmdfinal, "INVITE %s", name);
  send_data(user->cli_info.socket, cmdfinal);
  return (SUCCESS);
}
