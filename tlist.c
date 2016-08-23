/*
  +---------------------+
  |  Created By Rel4x_R |
  |  On May, 2016	|
  +---------------------+
*/

#include	"tlist.h"

struct s_list*	CreateList()
{
  return (0x0);
}

struct s_list*	CreateNode(void* data)
{
  t_list*	n;

  n = malloc(sizeof(t_list));
  if (n == 0) { return (0); }

  memset(n, 0x0, sizeof(t_list));
  n->data = data;
  n->prev = 0x0;
  n->next = 0;
  return (n);
}

struct s_list*	PushFront(struct s_list* list, struct s_list* node)
{
  if (node == 0) { return (0); }
  
  if (list == 0) 
    {
      node->prev = 0x0;
      node->next = 0x0;
      return (node);
    }
  
  node->next = list;
  node->next->prev = node;
  return (node);
}

struct s_list*	PushBack(struct s_list* list, struct s_list* node)
{
  if (node == 0) { return (0); }

  if (list == 0) 
    {
      node->prev = 0x0;
      node->next = 0x0;
      return (node);
    }
  
  while (list->next != 0)
    list = list->next;

  list->next = node;
  node->prev = list;
  
  while (list->prev != 0)
    list = list->prev;

  return (list);
}

struct s_list*	PopFront(struct s_list* list)
{
  if (list == 0x0) { return (0x0); }

  while (list->prev != 0x0)
    list = list->prev;

  list = RemoveNode(list, 0);
  return (list);
}

struct s_list*	PopBack(struct s_list* list)
{
  unsigned int	i;

  if (list == 0x0) { return (0x0); }
  
  while (list->prev != 0x0)
    list = list->prev;

  i = GetCount(list);
  list = RemoveNode(list, i - 1);
  return (list);
}

void*		GetFront(struct s_list* list)
{
  if (list == 0x0) { return (0x0); }

  while (list->prev != 0x0)
    list = list->prev;

  return (list->data);
}

void*		GetBack(struct s_list* list)
{
  if (list == 0x0) { return (0x0); }
  
  while (list->next != 0x0)
    list = list->next;
  
  return (list->data);
}

void*		GetIdx(struct s_list* list, unsigned int idx)
{
  unsigned int	i = 0;

  if (list == 0x0) { return (0x0); }
  
  while (list->prev != 0x0)
    list = list->prev;

  while (list && i < idx)
    {
      list = list->next;
      ++i;
    }

  if (list != 0x0)
    return (list->data);
  return (0x0);
}

void*		GetCurrent(struct s_list* list)
{
  if (list == 0x0) { return (0x0); }

  return (list->data);
}

unsigned int	GetCount(struct s_list* list)
{
  unsigned int	i = 0;

  if (list == 0x0) { return (0); }

  while (list->prev != 0x0)
    list = list->prev;

  while (list)
    {
      ++i;
      list = list->next;
    }

  return (i);
}

struct s_list*	InsertNode(struct s_list* list, struct s_list* n, unsigned int idx)
{
  unsigned int		i = 0;
  struct s_list*	t;

  if (list == 0x0 || n == 0x0) { return (0x0); }

  while (list->prev != 0x0)
    list = list->prev;

  while (list && i < idx)
    {
      t = list;
      list = list->next;
      ++i;
    }

  if (list != 0x0)
    {
      n->next = list;
      list->prev = n;
      if (list->prev != 0x0)
	{
	  n->prev = list->prev;
	  list->prev->next = n;
	}
      else
	  n->prev = 0x0;
    }
  else
    {
      n->next = 0x0;
      n->prev = t;
      t->next = n;
      list = t;
    }
  
  while (list->prev != 0x0)
    list = list->prev;

  return (list);
}

struct s_list*	RemoveNode(struct s_list* list, unsigned int idx)
{
  t_list*	t, *p, *n;
  int		i = 0;

  if (list == 0) { return (0x0); }

  t = list;
  while (t && i < idx)
    {
      t = t->next;
      ++i;
    }

  if (t)
    {
      p = t->prev;
      n = t->next;

      if (p != 0x0 && n != 0x0)
	{
	  p->next = n;
	  n->prev = p;
	  free(t);
	  return (list);
	}
      else if (p == 0x0)
	{
	  n->prev = 0x0;
	  list = list->next;
	  free(t);
	  return (list);
	}
      else if (n == 0x0)
	{
	  p->next = 0x0;
	  free(t);
	  return (list);
	}
      else if (p == 0x0 && n == 0x0)
	{
	  free(t);
	  return (0x0);
	}
      else
	return (0x0);
    }
  return (list);
}

int		ExAction(struct s_list* list, void (*func)(void*))
{
  if (list == 0) { return (0); }

  while (list != 0)
    {
      func(list->data);
      list = list->next;
    }
  return (1);
}

void		FreeList(struct s_list* list)
{
  t_list*	tmp;

  while (list != 0)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void		FreeListData(struct s_list* list)
{
  while (list != 0)
    {
      free(list->data);
      list->data = 0x0;
      list = list->next;
    }
}

L_ITERATOR	InitIterator(struct s_list* list)
{
  t_list*	tmp;

  tmp = list;
  while (tmp->prev != 0x0)
    tmp = tmp->prev;
  return (tmp);
}

L_ITERATOR	NextIterator(L_ITERATOR i)
{
  i = i->next;
  return (i);
}

L_ITERATOR	PrevIterator(L_ITERATOR i)
{
  i = i->prev;
  return (i);
}

