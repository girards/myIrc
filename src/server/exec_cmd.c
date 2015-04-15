/*
** exec_cmd.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed Apr  8 18:38:55 2015 Nicolas Girardot
** Last update Mon Apr 13 20:42:43 2015 Serge Heitzler
*/

#include "server.h"

static t_commands	g_cmd[11] =
  {
    {"NICK", &cmd_nick},
    {"JOIN", &cmd_join},
    {"PART", &cmd_part},
    {"LOCK", &cmd_lock},
    {"INVITE", &cmd_invite},
    {"LIST", &cmd_list},
    {"PRIVMSG", &cmd_privmsg},
    {"NAMES", &cmd_users},
    {"TOPIC", &cmd_topic},
    {"AWAY", &cmd_away},
    {"KICK", &cmd_kick}
  };

int	is_cmd(const char *cmd)
{
  int	i;

  i = 0;
  while (i < 11)
    {
      if (!strncmp(g_cmd[i].name, cmd, strlen(g_cmd[i].name)))
	return (i);
      i++;
    }
  return (NO);
}

int	exec_cmd(t_server *server, t_user *user, const char *cmd)
{
  int	ret;

  if ((ret = is_cmd(cmd)) != NO)
    g_cmd[ret].ptr_func(server, user, cmd);
  else
    cmd_msg(server, user, cmd);
  return (ERROR);
}
