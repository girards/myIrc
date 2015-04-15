/*
** cmd_nick.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed Apr  8 14:37:24 2015 Serge Heitzler
** Last update Mon Apr 13 20:28:12 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_nick(t_client *user, const char *command)
{
  char	        nickname[30];
  char		cmd[50];
  char		*cmdfinal;

  sscanf(command, "%s %s", cmd, nickname);
  user->nickname = strdup(nickname);
  cmdfinal = malloc(strlen("NICK") + strlen(nickname) + 2);
  sprintf(cmdfinal, "NICK %s", nickname);
  send_data(user->cli_info.socket, cmdfinal);
  return (SUCCESS);
}
