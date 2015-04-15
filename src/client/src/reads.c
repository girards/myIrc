/*
** reads.c for irc in /home/girard_s/PSU_2014_myirc/src/client/src
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 15:43:58 2015 Girardot Nicolas
** Last update Mon Apr 13 21:53:09 2015 Serge Heitzler
*/

#include "client.h"

int	read_prompt(char *buffer)
{
  char *end_of_put;

  if (fgets(buffer, 4096, stdin))
    {
      if ((end_of_put = (strchr(buffer, '\n'))))
	buffer[end_of_put - buffer] = '\0';
      return (0);
    }
  return (-1);
}

int	read_from_server(int sock, char *buffer)
{
  receive_data(sock, buffer, 4096);
  return (0);
}
