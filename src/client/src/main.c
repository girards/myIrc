/*
** main.c for my_irc in /home/girard_s/PSU_2014_myirc/src/client/src
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 11:16:33 2015 Girardot Nicolas
** Last update Mon Apr 13 21:53:36 2015 Serge Heitzler
*/

#include "client.h"

int	init_client(t_client *client)
{
  client->cli_info.proto = getprotobyname("TCP");
  client->cli_info.socket = socket(AF_INET,
				   SOCK_STREAM, client->cli_info.proto->p_proto);
  client->cli_info.s_in.sin_family = AF_INET;
  return (0);
}

int	do_connect(t_client *client)
{
  if (connect(client->cli_info.socket,
	      (const struct sockaddr *)&client->cli_info.s_in,
	      sizeof(client->cli_info.s_in)))
    {
      close(client->cli_info.socket);
      return (-1);
    }
  return (0);
}

int	my_connect(t_client *client)
{
  int	fd;

  FD_ZERO(&client->rfds);
  FD_ZERO(&client->wfds);
  FD_SET(STDIN_FILENO, &client->rfds);
  FD_SET(client->cli_info.socket, &client->rfds);
  FD_SET(client->cli_info.socket, &client->rfds);
  if (client->cli_info.socket == -1)
    fd = STDERR_FILENO;
  else
    fd = client->cli_info.socket;
  select(fd + 1, &client->rfds, &client->wfds, NULL, NULL);
  return (0);
}

int	loop(t_client *client)
{
  char	buffer[4096];

  while (42)
    {
      my_connect(client);
      if (FD_ISSET(STDIN_FILENO, &client->rfds))
	{
	  read_prompt(buffer);
	  exec_cmd(client, buffer);
	}
      else if (FD_ISSET(client->cli_info.socket, &client->rfds))
	{
	  read_from_server(client->cli_info.socket, buffer);
	  printf("%s", buffer);
	}
    }
  return (0);
}

int	main()
{
  t_client	client;
  char		*buffer;

  buffer = malloc(4096);
  client.nickname = NULL;
  client.connected = 0;
  init_client(&client);
  read_prompt(buffer);
  exec_cmd(&client, buffer);
  loop(&client);
  return (0);
}
