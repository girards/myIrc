/*
** client.h for my_irc in /home/girard_s/PSU_2014_myirc/src/client/src
**
** Made by Girardot Nicolas
** Login   <girard_s@epitech.net>
**
** Started on  Mon Apr 13 13:10:54 2015 Girardot Nicolas
** Last update Mon Apr 13 21:57:04 2015 Serge Heitzler
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>

# define COLOR_RED "\x1b[31m"
# define COLOR_BLUE "\x1b[36m"
# define COLOR_AZUR "\x1b[36m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_RESET "\x1b[0m"
# define SUCCESS -1
# define ERROR -2
# define YES -1
# define NO -2

typedef struct	s_commands
{
  char		*name;
  int		(*ptr_func)();
}		t_commands;

typedef struct		s_cli_info
{
  struct protoent	*proto;
  struct sockaddr_in	s_in;
  int			socket;
}			t_cli_info;

typedef struct s_client
{
  int	connected;
  t_cli_info	cli_info;
  char	*nickname;
  fd_set	wfds;
  fd_set	rfds;
}	       t_client;

int	read_prompt(char *);
int	read_from_server(int, char *);
int	init_client(t_client *);
int	my_connect(t_client *);
int	loop(t_client *);
int	receive_data(int, char *, size_t);
int	send_data(int, const char *);
int	set_connection(t_client *, char **);
void	set_addr(t_client *, const char *);
void	set_port(t_client *, const int);
int	do_connect(t_client *);
int	cmd_away(t_client *, const char *);
int	cmd_lock(t_client *, const char *);
int	cmd_topic(t_client *, const char *);
int	cmd_invite(t_client *, const char *);
int	cmd_msg(t_client *, const char *);
int	cmd_users(t_client *, const char *);
int	cmd_join(t_client *, const char *);
int	cmd_nick(t_client *, const char *);
int	cmd_kick(t_client *, const char *);
int	cmd_part(t_client *, const char *);
int	cmd_list(t_client *, const char *);
int	cmd_privmsg(t_client *, const char *);
int	cmd_quit(t_client *, const char *);
int	cmd_serv(t_client *, const char *);
int	is_cmd(const char *);
int	exec_cmd(t_client *, const char *);

#endif /* !CLIENT_H_ */
