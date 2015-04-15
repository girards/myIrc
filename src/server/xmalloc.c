/*
** xmalloc.c for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue Apr  7 23:17:45 2015 Serge Heitzler
** Last update Fri Apr 10 03:26:53 2015 Serge Heitzler
*/

#include "server.h"

void	*xmalloc(size_t size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      fprintf(stderr, COLOR_RED "Cannot alloc\n" COLOR_RESET);
      return (NULL);
    }
  return (s);
}
