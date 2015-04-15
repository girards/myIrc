/*
** cmd_part.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 22:31:58 2015 Nicolas Girardot
** Last update Mon Apr 13 20:27:44 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_part(t_client *user, const char *command)
{
  char	        nickname[30];
  char		cmd[50];
  char		*cmdfinal;

  sscanf(command, "%s %s", cmd, nickname);
  user->nickname = strdup(nickname);
  cmdfinal = malloc(strlen("PART") + strlen(nickname) + 2);
  sprintf(cmdfinal, "PART %s", nickname);
  send_data(user->cli_info.socket, cmdfinal);
  return (SUCCESS);
}
