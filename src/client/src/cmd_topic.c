/*
** cmd_topic.c for my_irc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 22:36:03 2015 Girardot Nicolas
** Last update Mon Apr 13 20:16:02 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_topic(t_client *user, const char *command)
{
  char	        name[140];
  char		cmd[15];
  char		*cmdfinal;

  sscanf(command, "%s %s", cmd, name);
  cmdfinal = malloc(strlen("TOPIC") + strlen(name) + 2);
  sprintf(cmdfinal, "TOPIC %s", name);
  send_data(user->cli_info.socket, cmdfinal);
  return (SUCCESS);
}
