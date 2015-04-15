/*
** cmd_join.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server/commands
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 17:49:10 2015 Nicolas Girardot
** Last update Mon Apr 13 20:52:45 2015 Serge Heitzler
*/

#include "server.h"

void		show_topic(t_channel *channel, int fd)
{
  char		*final;

  if ((strcmp(channel->topic, "")) != 0)
    {
      final = xmalloc(sizeof(char) *
		      (80 + strlen(channel->channel_name) + strlen(channel->topic)));
      memset(final, 0,
	     80 + strlen(channel->channel_name) + strlen(channel->topic));
      sprintf(final, COLOR_BLUE "[CHANNEL_NAME] : %s\n[TOPIC] : %s\n"
	      COLOR_RESET, channel->channel_name, channel->topic);
      send_data(fd, final);
    }
  else
    send_data(fd, COLOR_BLUE
	      "[TOPIC ISN'T SET ON THIS CHANNEL]\n" COLOR_RESET);
}

t_channel	*create_channel(char *channel_name, t_user *user)
{
  t_channel	*channel;

  if ((channel = xmalloc(sizeof(t_channel))) == NULL)
    return (NULL);
  if ((channel->user_connected = create_list()) == NULL)
    return (NULL);
  if ((channel->user_invited = create_list()) == NULL)
    return (NULL);
  if ((channel->last_messages = create_list()) == NULL)
    return (NULL);
  channel->user_connected->length = 0;
  channel->user_invited->length = 0;
  channel->last_messages->length = 0;
  channel->is_private = 0;
  channel->channel_name = strdup(channel_name);
  channel->topic = strdup("");
  channel->nbr_connected = 1;
  channel->operator = user->nickname;
  return (channel);
}

void		show_join_information(t_server *server, t_channel *channel, t_user *user)
{
  push_in_list(channel->user_connected, user->nickname);
  user->channel_name = strdup(channel->channel_name);
  printf(COLOR_BLUE "%s has joined channel %s\n"
	 COLOR_RESET, user->nickname, channel->channel_name);
  send_msg_to_channel(server, user, "[JOINED THE CHANNEL]\n");
  show_topic(channel, user->fd);
  show_message(channel, user->fd);
}

int		check_pos_and_create(t_server *server, t_user *user, char *channel_name)
{
  t_channel	*channel;
  int		pos_channel;

  pos_channel = does_channel_exist(channel_name, server->channels);
  if ((pos_channel) == ERROR)
    {
      if ((channel = create_channel(channel_name, user)) == NULL)
	return (ERROR);
      channel->operator = strdup(user->nickname);
      push_in_list(server->channels, channel);
    }
  pos_channel = does_channel_exist(channel_name, server->channels);
  channel = get_elem_at_pos(server->channels, pos_channel);
  if ((is_possible_to_join(channel, user)) == NO)
    return (ERROR);
  show_join_information(server, channel, user);
  return (SUCCESS);
}

int		cmd_join(t_server *server, t_user *user, const char *command)
{
  char	        name[29];
  char	        channel_name[30];
  char		cmd[15];

  if ((is_nickname_set(user->nickname, user->fd)) == NO)
    return (ERROR);
  if (user->channel_name != NULL)
    delete_user_in_channel(server->channels,
			   user->nickname, user->channel_name);
  sscanf(command, "%s %s", cmd, name);
  if (name[0] != '#')
    sprintf(channel_name, "#%s", name);
  else
    sprintf(channel_name, "%s", name);
  if ((check_pos_and_create(server, user, channel_name)) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
