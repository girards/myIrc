/*
** channel_list.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue Apr  7 15:39:03 2015 Serge Heitzler
** Last update Fri Apr 10 10:58:05 2015 Serge Heitzler
*/

#include "server.h"

int		is_channel_existing(t_list *channels, char *channel_name)
{
  t_node	*tmp;
  t_channel	*chann;

  tmp = channels->start;
  while (tmp)
    {
      chann = (t_channel*)tmp->data;
      if ((strcmp(chann->channel_name, channel_name)) != 0)
	tmp = tmp->next;
      else
	return (YES);
    }
  return (NO);
}

void		show_all_channels(t_list *channels, t_user *user)
{
  t_node	*tmp;
  t_channel	*chann;
  char		*formated;

  tmp = channels->start;
  while (tmp)
    {
      chann = (t_channel*)tmp->data;
      formated = xmalloc((strlen(chann->channel_name) + 25) * sizeof(char));
      memset(formated, 0, (strlen(chann->channel_name) + 25)),
      sprintf(formated, COLOR_BLUE "%s\n" COLOR_RESET, chann->channel_name);
      send_data(user->fd, formated);
      tmp = tmp->next;
      free(formated);
    }
}
