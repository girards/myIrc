/*
** cmd_users.c for IRC in /home/girard_s/PSU_2014_myirc/src/server
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 21:54:37 2015 Girardot Nicolas
** Last update Mon Apr 13 21:18:19 2015 Girardot Nicolas
*/

#include "client.h"

int		cmd_users(t_client *user, const char *command)
{
  command = command;
  send_data(user->cli_info.socket, "NAMES\n");
  return (0);
}
