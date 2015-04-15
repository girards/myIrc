/*
** show_message.c for myirc in /home/girard_s/PSU_2014_myirc/src/server
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Fri Apr 10 11:07:55 2015 Girardot Nicolas
** Last update Fri Apr 10 11:17:09 2015 Serge Heitzler
*/

#include "server.h"

void		show_message(t_channel *channel, int fd)
{
  char		*message;
  size_t	i;

  if (channel->last_messages->length < 10)
    i = 0;
  else
    i = channel->last_messages->length - 10;
  while (i < channel->last_messages->length)
    {
      message = (char *)get_elem_at_pos(channel->last_messages, i);
      send_data(fd, message);
      i++;
    }
}
