/*
** cmd_list.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 22:41:57 2015 Nicolas Girardot
** Last update Mon Apr 13 20:41:20 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_list(t_client *user, const char *command)
{
  command = command;
  send_data(user->cli_info.socket, "LIST");
  return (0);
}
