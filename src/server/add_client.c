/*
** add_client.c for my_ir  in /home/nicolas/rendu/PSU_2014_myirc/src/server
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Wed Apr  8 14:29:30 2015 Nicolas Girardot
** Last update Mon Apr 13 20:36:23 2015 Serge Heitzler
*/

#include"server.h"

int			get_user_ip(t_user *user, struct sockaddr_in s_in)
{
  if ((user->ip = inet_ntoa(s_in.sin_addr)) == NULL)
    {
      perror(COLOR_RED "Error on IP\n" COLOR_RESET);
      return (ERROR);
    }
  return (SUCCESS);
}

int			get_user_socket(t_user *user,
					const t_server *server)
{
  socklen_t		s_insize;
  struct sockaddr_in	s_in;

  s_insize = sizeof(s_in);
  if ((user->fd = accept(server->serv_info.socket,
			     (struct sockaddr *)&s_in,
			     &s_insize)) == ERROR)
    {
      perror(COLOR_RED "Error on Accept\n" COLOR_RESET);
      return (ERROR);
    }
  if (get_user_ip(user, s_in) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			add_user(t_server *server)
{
  t_user		*user;

  if ((user = xmalloc(sizeof(t_user))) == NULL)
    {
      perror(COLOR_RED "Error on Malloc\n" COLOR_RESET);
      return (ERROR);
    }
  if (get_user_socket(user, server) == ERROR)
    return (ERROR);
  user->nickname = xmalloc(50 * sizeof(char));
  memset(user->nickname, 0, 50);
  user->nickname = strdup("");
  user->status = CONNECTED;
  push_in_list(server->users, user);
  printf(COLOR_GREEN "IP %s is connected\n" COLOR_RESET, user->ip);
  return (SUCCESS);
}
