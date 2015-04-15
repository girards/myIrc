/*
** cmd_list.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 22:41:57 2015 Nicolas Girardot
** Last update Fri Apr 10 04:00:57 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_list(t_server *server, t_user *user, const char *command)
{
  (void) server;
  (void) user;
  (void) command;
  if (is_nickname_set(user->nickname, user->fd) == NO)
    return (ERROR);
  printf(COLOR_BLUE "%s has requested channel list\n"
	 COLOR_RESET, user->nickname);
  show_all_channels(server->channels, user);
  return (SUCCESS);
}
