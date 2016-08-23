/*
  +---------------------+
  |  Created By Rel4x_R |
  |  On May, 2016	|
  +---------------------+
*/

#ifndef		__TLIST_H__
#define		__TLIST_H__

#include	<stdlib.h>
#include	<string.h>

typedef struct	s_list
{
  void*			data;
  struct s_list*	prev;
  struct s_list*	next;
}		t_list;

#define		L_ITERATOR		t_list*

#define		L_CREATE(l)		(l = CreateList())
#define		N_CREATE(n)		(CreateNode(n))
#define		L_PUSHFRONT(l, n)	(l = (PushFront(l, N_CREATE(n))))
#define		L_PUSHBACK(l, n)	(l = (PushBack(l, N_CREATE(n))))
#define		L_POPFRONT(l)		(l = PopFront(l))
#define		L_POPBACK(l)		(l = PopBack(l))
#define		L_GETFRONT(l)		(GetFront(l))
#define		L_GETBACK(l)		(GetBack(l))
#define		L_GETIDX(l, i)		(GetIdx(l, i))
#define		L_GETCUR(l)		(GetCurrent(l))
#define		L_GETCOUNT(l)		(GetCount(l))
#define		L_INSERT(l, v, i)	(l = InsertNode(l, N_CREATE(v), i))
#define		L_REMOVE(l, i)		(l = RemoveNode(l, i))
#define		L_ACTION(l, f)		(ExAction(l, f))
#define		L_INITIT(l, i)		(i = InitIterator(l))
#define		I_NEXT(i)		(i = NextIterator(i))
#define		I_PREV(i)		(i = PrevIterator(i))

struct s_list*	CreateList();
struct s_list*	CreateNode(void* data);
struct s_list*	PushFront(struct s_list* list, struct s_list* node);
struct s_list*	PushBack(struct s_list* list, struct s_list* node);
struct s_list*	PopFront(struct s_list* list);
struct s_list*	PopBack(struct s_list* list);
void*		GetFront(struct s_list* list);
void*		GetBack(struct s_list* list);
void*		GetIdx(struct s_list* list, unsigned int idx);
void*		GetCurrent(struct s_list* list);
unsigned int	GetCount(struct s_list* list);
struct s_list*	InsertNode(struct s_list* list, struct s_list* n, unsigned int idx);
struct s_list*	RemoveNode(struct s_list* list, unsigned int idx);
int		ExAction(struct s_list* list, void (*func)(void*));
void		FreeList(struct s_list* list);
void		FreeListData(struct s_list* list);
L_ITERATOR	InitIterator(struct s_list* list);
L_ITERATOR	NextIterator(L_ITERATOR i);
L_ITERATOR	PrevIterator(L_ITERATOR i);

#endif		// __TLIST_H__
