/*
** cmd_join.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 17:49:10 2015 Nicolas Girardot
** Last update Mon Apr 13 20:23:14 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_join(t_client *user, const char *command)
{
  char	        name[29];
  char		cmd[15];
  char		*cmdfinal;

  sscanf(command, "%s %s", cmd, name);
  cmdfinal = malloc(strlen("JOIN") + strlen(name) + 2);
  sprintf(cmdfinal, "JOIN %s", name);
  send_data(user->cli_info.socket, cmdfinal);
  return (SUCCESS);
}
