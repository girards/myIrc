/*
** list.h for myirc in /home/heitzl_s/rendu/PSU_2014_myirc/src/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu Apr  2 14:28:32 2015 Serge Heitzler
** Last update Mon Apr 13 21:56:24 2015 Serge Heitzler
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>
# include <stdio.h>

typedef enum e_type
  {
    USER,
    CHANNEL,
    STRING
  }		e_type;

typedef struct s_node
{
  e_type	type;
  void		*data;
  struct s_node *next;
  struct s_node *prev;
}		t_node;

typedef struct s_list
{
  size_t	length;
  t_node	*start;
  t_node	*end;
}		t_list;

/* list.c */
t_list		*create_list();
void		free_my_list(t_list *);

/* add_in_list.c */
void		add_node(t_list *, t_node *);
void		push_in_list(t_list *, void *);

/* xmalloc.c */
void		*xmalloc(size_t size);

#endif  /* !LIST_H_ */
