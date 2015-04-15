/*
** cmd_msg.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed Apr  8 18:15:21 2015 Nicolas Girardot
** Last update Mon Apr 13 21:16:13 2015 Girardot Nicolas
*/

#include "client.h"

int	cmd_msg(t_client *user, const char *command)
{
  char	*cmd_final;

  cmd_final = malloc(strlen(command) + 2);
  sprintf(cmd_final, "%s\n", command);
  send_data(user->cli_info.socket, cmd_final);
  return (0);
}
