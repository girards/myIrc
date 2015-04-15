/*
** cmd_privmsg.c for myirc in /home/girard_s/PSU_2014_myirc/src/server/commands
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Thu Apr  9 21:02:29 2015 Girardot Nicolas
** Last update Mon Apr 13 20:21:29 2015 Serge Heitzler
*/

#include <sys/time.h>
#include <time.h>
#include "server.h"

void		show_privmsg(t_user *user, char *msg, char *tmbuf, int fd)
{
  char			*msgfinal;

  msgfinal = xmalloc((strlen(tmbuf) +
		      strlen(user->nickname) + strlen(msg) + 45));
  memset(msgfinal, 0, (strlen(tmbuf) +
		       strlen(user->nickname) + strlen(msg) + 45));
  sprintf(msgfinal, "[%s] - " COLOR_AZUR "[PRIVMSG FROM %s]"
	  COLOR_RESET " : %s\n", tmbuf, user->nickname, msg);
  send_data(fd, msgfinal);
}

int		cmd_privmsg(t_server *server, t_user *user, const char *command)
{
  t_user		*dest;
  char			cmd[50];
  char			to[50];
  char			msg[4096];
  struct timeval	tv;
  time_t		nowtime;
  struct tm		*nowtm;
  char			tmbuf[64];

  gettimeofday(&tv, NULL);
  nowtime = tv.tv_sec;
  nowtm = localtime(&nowtime);
  strftime(tmbuf, sizeof(tmbuf), "%H:%M:%S", nowtm);
  sscanf(command, "%s %s %4050[^\n]", cmd, to, msg);
  dest = get_user_in_list(server->users, to);
  if ((is_user_null(dest, user, to)) == YES)
    return (ERROR);
  if ((is_away(dest, user->fd) == YES))
    return (ERROR);
  show_privmsg(user, msg, tmbuf, dest->fd);
  return (SUCCESS);
}
