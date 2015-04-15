/*
** receive_data.c for my_ric in /home/nicolas/rendu/PSU_2014_myirc/src/server
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed Apr  8 15:10:28 2015 Nicolas Girardot
** Last update Mon Apr 13 17:27:22 2015 Girardot Nicolas
*/

#include "client.h"

int		receive_data(int socket, char *buffer, size_t len)
{
  int		n;

  if ((n = read(socket, buffer, len - 1)) == ERROR)
    {
      perror(COLOR_RED "Error on read\n" COLOR_RESET);
      n = 0;
    }
  buffer[n] = '\0';
  return (n);
}

int		send_data(int socket, const char *buffer)
{
  int		n;
  size_t	len;

  len = strlen(buffer);
  if ((n = write(socket, buffer, len)) == ERROR)
    {
      perror(COLOR_RED "Error on send\n" COLOR_RESET);
      return (ERROR);
    }
  return (n);
}
