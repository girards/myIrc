/*
** server.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu Apr  2 13:56:54 2015 Serge Heitzler
** Last update Fri Apr 10 15:53:06 2015 Girardot Nicolas
*/

#include "server.h"

int	init_socket(t_server *server)
{
  if ((server->serv_info.socket = socket(AF_INET,
				 SOCK_STREAM,
				 server->serv_info.proto->p_proto)) == ERROR)
    {
      perror(COLOR_RED "Error on initialization on socket\n" COLOR_RESET);
      return (ERROR);
    }
  server->serv_info.s_in.sin_family = AF_INET;
  server->serv_info.s_in.sin_port = htons(server->port);
  server->serv_info.s_in.sin_addr.s_addr = htons(INADDR_ANY);
  return (SUCCESS);
}

int	init_protocol(t_server *server)
{
  if ((server->serv_info.proto = getprotobyname("TCP")) == NULL)
    {
      perror(COLOR_RED "Error on initialization on protocol\n" COLOR_RESET);
      return (ERROR);
    }
  return (SUCCESS);
}

int	init_server(t_server *server)
{
  if (init_protocol(server) == ERROR)
    return (ERROR);
  if (init_socket(server) == ERROR)
    return (ERROR);
  if (bind(server->serv_info.socket,
	   (const struct sockaddr *)&server->serv_info.s_in,
	   sizeof(server->serv_info.s_in)))
    {
      perror(COLOR_RED "Error on bind\n" COLOR_RESET);
      close(server->serv_info.socket);
      return (ERROR);
    }
  if (listen(server->serv_info.socket, 42))
    {
      perror(COLOR_RED "Error on listen\n" COLOR_RESET);
      close(server->serv_info.socket);
      return (ERROR);
    }
  printf(COLOR_BLUE "Server created\n" COLOR_RESET);
  return (SUCCESS);
}

int	launch_server(t_server *server)
{
  if (init_server(server) == SUCCESS)
    {
      printf(COLOR_GREEN "Server launched !\n" COLOR_RESET);
      loop_on_server(server);
      return (SUCCESS);
    }
  else
    return (ERROR);
}
