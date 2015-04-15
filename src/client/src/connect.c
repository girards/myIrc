/*
** connect.c for my_irc in /home/girard_s/PSU_2014_myirc/src/client/src
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 18:18:56 2015 Girardot Nicolas
** Last update Mon Apr 13 20:52:13 2015 Girardot Nicolas
*/

#include "client.h"

int	set_connection(t_client *client, char **av)
{
  set_addr(client, av[0]);
  set_port(client, atoi(av[1]));
  if (init_client(client) == -1)
    return (-1);
  if (do_connect(client) == -1)
    return (-1);
  return (0);
}

void	set_addr(t_client *client, const char *address)
{
  client->cli_info.s_in.sin_addr.s_addr = inet_addr(address);
}

void	set_port(t_client *client, const int port)
{
  client->cli_info.s_in.sin_port = htons(port);
}
