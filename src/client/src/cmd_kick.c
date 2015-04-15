/*
** cmd_kick.c for my_ric in /home/girard_s/PSU_2014_myirc/src/client
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 20:27:51 2015 Girardot Nicolas
** Last update Mon Apr 13 21:26:58 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_kick(t_client *user, const char *command)
{
  char	        nickname[30];
  char		cmd[50];
  char		*cmdfinal;

  sscanf(command, "%s %s", cmd, nickname);
  user->nickname = strdup(nickname);
  cmdfinal = malloc(strlen("KICK") + strlen(nickname) + 2);
  sprintf(cmdfinal, "KICK %s", nickname);
  send_data(user->cli_info.socket, cmdfinal);
  return (SUCCESS);
}
