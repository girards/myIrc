/*
** cmd_nick.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed Apr  8 14:37:24 2015 Serge Heitzler
** Last update Mon Apr 13 21:54:36 2015 Serge Heitzler
*/

#include "server.h"

int		change_nickname_in_channel(t_server *server, char *old_nickname,
					   char *new_nickname, char *channel_name)
{
  t_node	*tmpd;
  t_channel	*channel;
  t_user	*user;

  channel = get_channel_in_list(server->channels, channel_name);
  tmpd = channel->user_connected->start;
  if (strcmp(old_nickname, "") == 0)
    {
      push_in_list(channel->user_connected, new_nickname);
      return (SUCCESS);
    }
  user = get_user_in_list(server->users, old_nickname);
  if ((strcmp(old_nickname, channel->operator)) == 0)
    channel->operator = strdup(new_nickname);
  user->nickname = strdup(new_nickname);
  while (tmpd)
    {
      if ((strcmp((char*)tmpd->data, old_nickname)) != 0)
	tmpd = tmpd->next;
      else
	tmpd->data = strdup(new_nickname);
    }
  return (SUCCESS);
}

int		is_nickname_already_given(t_server *server, t_user *user, char *nickname)
{
  t_node	*tmp;
  t_user	*user_tmp;

  tmp = server->users->start;
  while (tmp)
    {
      user_tmp = (t_user*)tmp->data;
      if ((strcmp(user_tmp->nickname, nickname)) != 0)
	tmp = tmp->next;
      else
	{
	  kick_user_from_channel(server, user->nickname, user->channel_name);
	  kick_user_from_channel(server, user_tmp->nickname, user_tmp->channel_name);
	  close(user_tmp->fd);
	  close(user->fd);
	  printf(COLOR_BLUE "%s & %s kicked from server, will have same nickname\n"
		 COLOR_RESET, user->nickname, user_tmp->nickname);
	  return (YES);
	}
    }
  return (NO);
}

int		cmd_nick(t_server *server, t_user *user, const char *command)
{
  char	        nickname[30];
  char		cmd[50];

  sscanf(command, "%s %s", cmd, nickname);
  if ((is_nickname_already_given(server, user, nickname)) == YES)
    return (ERROR);
  if (user->channel_name == NULL)
    printf(COLOR_BLUE "New nickname set : %s\n" COLOR_RESET, nickname);
  else
    change_nickname_in_channel(server, user->nickname,
			       nickname, user->channel_name);
  user->nickname = strdup(nickname);
  return (SUCCESS);
}
