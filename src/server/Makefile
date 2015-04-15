##
## Makefile for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Mon Mar 23 10:18:33 2015 Serge Heitzler
## Last update Mon Apr 13 21:45:45 2015 Serge Heitzler
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra
CFLAGS		+= 	-I.

LDFLAGS		=

CMD_DIR		=	commands/

SRCS		= 	main.c				\
			server.c			\
			manage_server_errors.c		\
			loop_on_server.c		\
			list.c				\
			user_list.c			\
			channel_list.c			\
			add_in_list.c			\
			delete_in_list.c		\
			kick_user_list.c		\
			get_in_list.c			\
			add_client.c			\
			xmalloc.c			\
			data_sr.c			\
			send_msg_to_channel.c		\
			exec_cmd.c			\
			show_message.c			\
			$(CMD_DIR)cmd_join.c		\
			$(CMD_DIR)cmd_join2.c		\
			$(CMD_DIR)cmd_away.c		\
			$(CMD_DIR)cmd_part.c		\
			$(CMD_DIR)cmd_msg.c		\
			$(CMD_DIR)cmd_invite.c		\
			$(CMD_DIR)cmd_lock.c		\
			$(CMD_DIR)manage_cmd_errors.c	\
			$(CMD_DIR)cmd_nick.c		\
			$(CMD_DIR)cmd_kick.c		\
			$(CMD_DIR)cmd_list.c		\
			$(CMD_DIR)cmd_privmsg.c		\
			$(CMD_DIR)cmd_users.c   	\
			$(CMD_DIR)cmd_topic.c

NAME		= 	server

OBJS		= 	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)		: 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
			cp $(NAME) ../../

clean		:
			$(RM) $(OBJS)
			$(RM) *~ *#

fclean		:	clean
			$(RM) $(NAME)
			$(RM) ../../$(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
