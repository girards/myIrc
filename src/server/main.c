/*
** main.c for server_irc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Mon Mar 23 10:20:58 2015 Serge Heitzler
** Last update Fri Apr 10 10:59:22 2015 Serge Heitzler
*/

#include "server.h"

int	main(int ac, char **av)
{
  t_server *server;

  server = xmalloc(sizeof(t_server));
  server->users = create_list();
  server->channels = create_list();
  test_args(ac, av);
  server->port = atoi(av[1]);
  launch_server(server);
  return (1);
}
