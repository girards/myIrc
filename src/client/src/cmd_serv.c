/*
** cmd_serv.c for my_irc in /home/girard_s/PSU_2014_myirc/src/client
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 20:47:03 2015 Girardot Nicolas
** Last update Mon Apr 13 21:38:39 2015 Girardot Nicolas
*/

#include "client.h"

int	cmd_serv(t_client *cli, const char *cmd)
{
  char  ccmd[50];
  char	adresse[50];
  char	port[10];
  char	*data[2];

  sscanf(cmd ,"%s %[^:]%*c%s", ccmd, adresse, port);
  data[0] = strdup(adresse);
  data[1] = strdup(port);
  set_connection(cli, data);
  cli->connected = 1;
  return (0);
}
