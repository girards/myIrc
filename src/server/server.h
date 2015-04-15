/*
** server.h for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu Apr  2 13:38:32 2015 Serge Heitzler
** Last update Mon Apr 13 20:49:04 2015 Serge Heitzler
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "list.h"

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

typedef	enum	e_status
  {
    AWAY,
    CONNECTED
  }		e_status;

typedef	enum	e_right
  {
    BASIC,
    OPERATOR
  }		e_right;

typedef struct	s_user
{
  int		fd;
  e_status	status;
  char		*nickname;
  char		*channel_name;
  e_right	right;
  char		*ip;
}		t_user;

typedef struct	s_channel
{
  char		*topic;
  size_t	nbr_connected;
  char		*channel_name;
  t_list	*user_connected;
  t_list	*user_invited;
  t_list	*last_messages;
  char		*operator;
  int		is_private;
}		t_channel;

typedef struct		s_serv_info
{
  struct protoent	*proto;
  struct sockaddr_in	s_in;
  int			socket;
}			t_serv_info;

typedef struct	s_server
{
  int		port;
  t_serv_info	serv_info;
  int		fd_max;
  fd_set	readfds;
  fd_set	writefds;
  t_list	*users;
  t_list	*channels;
}		t_server;

/* ./command/cmd_$CMD.c */
int		cmd_part(t_server *, t_user *, const char *);
int		cmd_list(t_server *, t_user *, const char *);
int		cmd_nick(t_server *, t_user *, const char *);
int		cmd_msg(t_server *, t_user *, const char *);
int		cmd_privmsg(t_server *, t_user *, const char *);
void		show_privmsg(t_user *, char *, char *, int);
int		cmd_users(t_server *, t_user *, const char *);
int		cmd_topic(t_server *, t_user *, const char *);
int		cmd_away(t_server *, t_user *, const char *);
int		cmd_lock(t_server *, t_user *, const char *);
int		change_nickname_in_channel(t_server *, char *, char *, char *);

/* cmd_kick.c */
int		cmd_kick(t_server *, t_user *, const char *);
void		show_kick(t_server *, t_user *, char *);

/* cmd_join.c */
t_channel	*create_channel(char *, t_user *);
void		show_topic(t_channel *, int);
int		cmd_join(t_server *, t_user *, const char *);
int		check_pos_and_create(t_server *, t_user *, char *);
void		show_join_information(t_server *, t_channel *, t_user *);

/* cmd_join2.c */
int		is_possible_to_join(t_channel *, t_user *);
int		does_channel_exist(char *, t_list *);
int		is_invited(t_channel *, t_user *);

/* cmd_invite.c */
int		cmd_invite(t_server *, t_user *, const char *);
void		show_invited(t_server *, t_user *, char *);
void		show_invitation(t_channel *, t_user *, char *, int);

/* add_client.c */
int		get_user_ip(t_user *, struct sockaddr_in);
int		get_user_socket(t_user *, const t_server *);
int		add_user(t_server *);

/* channel_list.c */
int		is_channel_existing(t_list *, char *);
void		show_all_channels(t_list *, t_user*);

/* data_sr.c */
int		receive_data(int, char *, size_t);
int		send_data(int, const char *);

/* delete_in_list.c */
void		delete_node(t_list *, t_node *);
int		delete_channel_in_user(t_list *, char *);
int		delete_user_in_channel(t_list *, char *, char *);
int		delete_user_in_list(t_server *, char *);

/* exec_cmd.c */
int		is_cmd(const char*);
int		exec_cmd(t_server *, t_user*, const char *);

/* get_in_list.c */
char      	*get_string_in_list(t_list *, char *);
t_channel      	*get_channel_in_list(t_list *, char *);
t_user		*get_user_in_list(t_list *, char *);
void		*get_elem_at_pos(t_list *, size_t);
size_t		get_pos_for_elem(t_list *, t_node *);

/* kick_user_list.c */
int		kick_user_from_channel(t_server *, char *, char *);
int		kick_user_from_server(t_server *, char *);
t_node		*get_node_user(t_server *, char *);

/* loop_on_server.c */
int		respond(t_server *);
int		set_max_fds(t_server *);
void		set_fds(t_server *);
int		loop_on_server(t_server *);

/* manage_server_errors.c */
void		test_args(int, char **);

/* manage_cmd_errors */
int		is_user_null(t_user *, t_user *, char *);
int		is_nickname_set(char *, int);
int		is_away(t_user *, int);

/* send_msg_to_channel.c */
char		*format_msg(char *, t_user *, const char *, char *);
int		send_msg_to_channel(t_server *, t_user * , const char *);

/* server.c */
int		init_socket(t_server *);
int		init_protocol(t_server *);
int		init_server(t_server *);
int		launch_server(t_server *);

/* show_message.c */
void		show_message(t_channel*, int);

/* user_list.c */
int		is_operator_in_channel(t_server *, char *, char *);
int		is_user_in_channel(t_server *, char *, char *);
int		is_user_existing(t_server *, char *);
int		show_users_in_channel(t_server *, char *, int);

# endif /* !SERVER_H_ */
