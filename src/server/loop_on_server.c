/*
** loop_on_server.c for my_irc in /home/nicolas/rendu/PSU_2014_myirc/src/server
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue Apr  7 15:22:58 2015 Nicolas Girardot
** Last update Mon Apr 13 20:35:28 2015 Serge Heitzler
*/

#include <errno.h>
#include "server.h"

int		respond(t_server *server)
{
  int		i;
  t_user	*user;
  char		buffer[4096];

  i = 0;
  if (server->users != NULL)
    {
      while (i < (int)server->users->length)
	{
	  user = (t_user *)get_elem_at_pos(server->users, i);
	  if (FD_ISSET(user->fd, &server->readfds) &&
	      FD_ISSET(user->fd, &server->writefds))
	    {
	      if (receive_data(user->fd, buffer, 4096) <= 0)
		{
		  respond(server);
	      	}
	      if (exec_cmd(server, user, buffer) == ERROR)
		return (ERROR);
	      memset(buffer, 0, 4096);
	    }
	  i++;
	}
    }
  return (SUCCESS);
}

int		set_max_fds(t_server *server)
{
  t_user	*user;

  if (server->users->length == 0)
    return (server->serv_info.socket);
  user = xmalloc(sizeof(t_user));
  user = (t_user *)server->users->end->data;
  return (user->fd);
}

void		set_fds(t_server *server)
{
  unsigned int	i;
  unsigned int	nb_users;
  t_user	*user;

  user = xmalloc(sizeof(t_user));
  FD_ZERO(&server->readfds);
  FD_ZERO(&server->writefds);
  FD_SET(STDIN_FILENO, &server->readfds);
  FD_SET(server->serv_info.socket, &server->readfds);
  if (server->users->length > 0)
    {
      if (server->fd_max == -1)
	server->fd_max = set_max_fds(server);
      i = 0;
      nb_users = server->users->length;
      while (i < nb_users)
	{
	  user = (t_user *)get_elem_at_pos(server->users, i);
	  FD_SET(user->fd, &server->readfds);
	  FD_SET(user->fd, &server->writefds);
	  if (user->fd > server->fd_max)
	    server->fd_max = user->fd;
	  i++;
	}
    }
}

int	loop_on_server(t_server *server)
{
  int	n;

  while (42)
    {
      set_fds(server);
      n = set_max_fds(server) + 1;
      if (select(n, &server->readfds, &server->writefds, NULL, NULL) == -1)
	{
	  fprintf(stderr, COLOR_RED "Select : Error on select\n" COLOR_RESET);
	  return (ERROR);
	}
      if (FD_ISSET(STDIN_FILENO, &server->readfds) != 0)
	return (ERROR);
      else if (FD_ISSET(server->serv_info.socket, &server->readfds))
	add_user(server);
      else
	respond(server);
      usleep(1);
    }
}
