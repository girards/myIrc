/*
** manage_server_errors.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu Apr  2 13:59:11 2015 Serge Heitzler
** Last update Mon Apr 13 19:38:44 2015 Girardot Nicolas
*/

#include "server.h"

void    test_args(int ac, char **av)
{
  int   i;

  if (ac != 2)
    {
      fprintf(stderr, COLOR_RED "ERROR" COLOR_RESET
             " : Wrong Usage : ./server [PORT]\n");
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (av[1][i] != '\0')
    {
      if (av[1][i] >= '0' && av[1][i] <= '9');
      else
	exit(EXIT_FAILURE);
      i++;
    }
  i = atoi(av[1]);
  if (i > 65535 || i < 0)
    {
      fprintf(stderr, COLOR_RED "ERROR" COLOR_RESET
             " : %d is not a valid port\n", i);
      exit(EXIT_FAILURE);
    }
}
