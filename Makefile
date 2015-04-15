##
## Makefile for myftp in /home/heitzl_s/rendu/PSU_2014_myftp
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Thu Mar 19 19:45:12 2015 Serge Heitzler
## Last update Mon Apr 13 21:44:59 2015 Serge Heitzler
##

MAKE		= 	make -C
CP		= 	cp -f

DIR_CLIENT	= 	src/client/
EXE_CLIENT	= 	src/client/client

DIR_SERV	=	src/server
EXE_SERV	=	src/server/serveur

all		:	client serveur

client		:
			@echo -e "\E[33;32mCompilation Client\033[0m"
			$(MAKE) $(DIR_CLIENT)

serveur		:
			@echo -e "\E[33;32mCompilation Serveur\033[0m"
			$(MAKE) $(DIR_SERV)

clean		:
			$(MAKE) $(DIR_CLIENT) clean
			$(MAKE) $(DIR_SERV) clean
			rm -rf *~ *#

fclean		:
			$(MAKE) $(DIR_CLIENT) fclean
			$(MAKE) $(DIR_SERV) fclean

re		:	 fclean all

.PHONY		:	 all clean fclean re client serveur
