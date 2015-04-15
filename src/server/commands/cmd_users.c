/*
** cmd_users.c for IRC in /home/girard_s/PSU_2014_myirc/src/server
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 21:54:37 2015 Girardot Nicolas
** Last update Mon Apr 13 20:21:12 2015 Serge Heitzler
*/

#include "server.h"

int	cmd_users(t_server *server, t_user *user, const char *command)
{
  command = command;
  printf(COLOR_BLUE "%s has requested user list connected in channel %s\n"
	 COLOR_RESET, user->nickname, user->channel_name);
  show_users_in_channel(server, user->channel_name, user->fd);
  return (SUCCESS);
}
