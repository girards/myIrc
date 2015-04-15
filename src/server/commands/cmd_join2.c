/*
** cmd_join2.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Mon Apr 13 20:26:43 2015 Serge Heitzler
** Last update Mon Apr 13 20:28:11 2015 Serge Heitzler
*/

#include "server.h"

int		is_invited(t_channel *channel, t_user *user)
{
  size_t       	i;
  char		*tmp;

  i = 0;
  while (i < channel->user_invited->length)
    {
      tmp = (char*)get_elem_at_pos(channel->user_invited, i);
      if (strcmp(tmp, user->nickname) == 0)
	return (YES);
      i++;
    }
  return (NO);
}

int		does_channel_exist(char *channel_name, t_list *channels)
{
  int		i;
  t_channel	*temp;

  i = 0;
  while (i < (int)channels->length)
    {
      temp = get_elem_at_pos(channels, i);
      if (strcmp(temp->channel_name, channel_name) == 0)
	return (i);
      i++;
    }
  return (ERROR);
}

int		is_possible_to_join(t_channel *channel, t_user *user)
{
  if ((channel->is_private) == 1 && (is_invited(channel, user)) == NO)
    {
      send_data(user->fd, COLOR_RED
		"[SERVER-INFO] : You are not allowed to join this channel\n" COLOR_RESET);
      return (NO);
    }
  return (YES);
}
