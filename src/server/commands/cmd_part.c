/*
** cmd_part.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 22:31:58 2015 Nicolas Girardot
** Last update Mon Apr 13 21:02:13 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_part(t_server *server, t_user *user, const char *command)
{
  char	cmd[50];
  char	channel_name[50];

  sscanf(command, "%s %s", cmd, channel_name);
  if (user->channel_name == NULL)
    return (ERROR);
  send_msg_to_channel(server, user, "[JUST LEFT THE CONVERSATION]\n");
  delete_user_in_channel(server->channels, user->nickname, user->channel_name);
  kick_user_from_channel(server, user->nickname, channel_name);
  return (SUCCESS);
}
