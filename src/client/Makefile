##
## Makefile for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/client
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Mon Mar 23 10:17:45 2015 Serge Heitzler
## Last update Mon Apr 13 21:45:43 2015 Serge Heitzler
##

CC		= 	gcc

RM		= 	rm -f

CFLAGS		+= 	-W -Wall -Werror -Wextra
CFLAGS		+= 	-I.

LDFLAGS		=

SRCS		= 	src/main.c 		\
			src/reads.c 		\
			src/data_sr.c		\
			src/connect.c		\
			src/cmd_away.c		\
			src/cmd_lock.c		\
			src/cmd_topic.c		\
			src/cmd_invite.c	\
			src/cmd_msg.c		\
			src/cmd_users.c		\
			src/cmd_join.c		\
			src/cmd_nick.c		\
			src/cmd_quit.c		\
			src/cmd_kick.c		\
			src/cmd_part.c		\
			src/cmd_list.c		\
			src/cmd_privmsg.c	\
			src/cmd_serv.c		\
			src/interpret.c


NAME		= 	client

OBJS		= 	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)		: 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
			cp $(NAME) ../../

clean		:
			$(RM) $(OBJS)
			$(RM) *~ *#

fclean		: 	clean
			$(RM) $(NAME)
			$(RM) ../../$(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re
