/*
** interpret.c for myirc in /home/girard_s/PSU_2014_myirc/src/client
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 19:56:51 2015 Girardot Nicolas
** Last update Mon Apr 13 21:50:58 2015 Serge Heitzler
*/

#include "client.h"

static t_commands	g_cmd[13] =
  {
    {"/server", &cmd_serv},
    {"/nick", &cmd_nick},
    {"/kick", &cmd_kick},
    {"/join", &cmd_join},
    {"/part", &cmd_part},
    {"/lock", &cmd_lock},
    {"/invite", &cmd_invite},
    {"/list", &cmd_list},
    {"/msg", &cmd_privmsg},
    {"/users", &cmd_users},
    {"/topic", &cmd_topic},
    {"/away", &cmd_away},
    {"/quit", &cmd_quit}
  };

int	is_cmd(const char *cmd)
{
  int	i;

  i = 0;
  while (i < 13)
    {
      if (!strncmp(g_cmd[i].name, cmd, strlen(g_cmd[i].name)))
	return (i);
      i++;
    }
  return (-2);
}

int	exec_cmd(t_client *user, const char *cmd)
{
  int	ret;

  if ((ret = is_cmd(cmd)) != -2)
    {
      if (ret == 0)
	g_cmd[ret].ptr_func(user, cmd);
      else if (user->connected == 0)
	printf("Please connect first to server\n");
      else
	g_cmd[ret].ptr_func(user, cmd);
    }
  else
    if (user->connected == 0)
      printf("Please connect first to server\n");
    else
      cmd_msg(user, cmd);
  return (ERROR);
}
