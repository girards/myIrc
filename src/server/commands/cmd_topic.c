/*
** cmd_topic.c for my_irc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 22:36:03 2015 Girardot Nicolas
** Last update Fri Apr 10 09:31:40 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_topic(t_server *server, t_user *user, const char *command)
{
  t_channel	*chan;
  char		cmd[50];
  char		topic[140];
  char		*final;

  sscanf(command, "%s %140[^\n]", cmd, topic);
  chan = get_channel_in_list(server->channels, user->channel_name);
  printf(COLOR_BLUE "%s has changed %s's topic\n"
	 COLOR_RESET, user->nickname, user->channel_name);
  final = xmalloc(strlen(topic) + 30);
  memset(final, 0, (strlen(topic) + 30));
  sprintf(final, COLOR_BLUE "%s\n" COLOR_RESET, topic);
  chan->topic = strdup(final);
  return (SUCCESS);
}
