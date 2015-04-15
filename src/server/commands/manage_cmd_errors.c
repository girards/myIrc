/*
** manage_cmd_errors.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Fri Apr 10 00:28:21 2015 Serge Heitzler
** Last update Mon Apr 13 14:19:28 2015 Serge Heitzler
*/

#include "server.h"

int	is_user_null(t_user *dest, t_user *user, char *to)
{
  if (dest == NULL)
    {
      printf(COLOR_RED "%s has tried to interact with an unknow user %s\n"
	     COLOR_RESET, user->nickname, to);
      send_data(user->fd, COLOR_YELLOW
		"[SERVER-INFO] : This user doesn't exist\n" COLOR_RESET);
      return (YES);
    }
  return (NO);
}

int	is_nickname_set(char *nickname, int fd)
{
  if (strcmp(nickname, "") == 0)
    {
      send_data(fd, COLOR_RED
		"Set a USERNAME before EXECUTING command\n" COLOR_RESET);
      printf(COLOR_RED
	     "Somebody tries to execute cmd w/out setting his name\n" COLOR_RESET);
      return (NO);
    }
  return (YES);
}

int	is_away(t_user *dest, int fd)
{
  if (dest->status == AWAY)
    {
      send_data(fd, COLOR_BLUE
		"[SERVER-INFO] : User is away\n" COLOR_RESET);
      return (YES);
    }
  if (dest == NULL)
    {
      send_data(fd, COLOR_RED
		"[SERVER-ERROR] : User is not connected\n" COLOR_RESET);
      return (YES);
    }
  return (NO);
}
