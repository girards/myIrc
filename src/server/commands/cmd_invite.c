/*
** cmd_invite.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Fri Apr 10 00:24:58 2015 Serge Heitzler
** Last update Mon Apr 13 21:55:56 2015 Serge Heitzler
*/

#include "server.h"

void		show_invited(t_server *server, t_user *user, char *name)
{
  char		*invited;

  invited = xmalloc(sizeof(char) * (20 + strlen(name)));
  memset(invited, 0, (20 + strlen(name)));
  sprintf(invited, "has invited %s\n", name);
  send_msg_to_channel(server, user, invited);
  printf(COLOR_BLUE "%s has invited %s in channel %s\n" COLOR_RESET,
	 user->nickname, name, user->channel_name);
}

void		show_invitation(t_channel *channel, t_user *user, char *name, int fd)
{
  char		*invitation;

  invitation = xmalloc(sizeof(char) * (70 + strlen(user->channel_name)));
  memset(invitation, 0, (70 + strlen(user->channel_name)));
  sprintf(invitation, COLOR_BLUE
	  "[SERVER-INFO] : You have been invited in %s\n"
	  COLOR_RESET, user->channel_name);
  send_data(fd, invitation);
  push_in_list(channel->user_invited, name);
}

int		cmd_invite(t_server *server, t_user *user, const char *command)
{
  t_channel	*channel;
  t_user	*user_invited;
  char	        name[29];
  char		cmd[15];

  sscanf(command, "%s %s", cmd, name);
  channel = get_channel_in_list(server->channels, user->channel_name);
  if (channel->is_private == 0)
    {
      send_data(user->fd, COLOR_BLUE
		"[SERVER-INFO] : You have to lock the channel first\n" COLOR_RESET);
      printf(COLOR_BLUE "%s tries to invite w/out locking the channel\n"
	     COLOR_RESET, user->nickname);
      return (ERROR);
    }
  user_invited = get_user_in_list(server->users, name);
  if ((is_user_null(user_invited, user, name)) == YES)
     return (ERROR);
  show_invited(server, user, name);
  show_invitation(channel, user, name, user_invited->fd);
  return (SUCCESS);
}
