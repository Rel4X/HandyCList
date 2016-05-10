/*
  +---------------------+
  |  Created By Rel4x_R |
  |  On May, 2016	|
  +---------------------+
*/

#ifndef		__TLIST_H__
#define		__TLIST_H__

#define		L_CREATE(n)		(CreateNode(n))
#define		L_PUSHFRONT(l, n)	(l = (PushFront(l, L_CREATE(n))))
#define		L_PUSHBACK(l, n)	(l = (PushBack(l, L_CREATE(n))))
#define		L_POPFRONT(l)		(l = PopFront(l));
#define		L_POPBACK(l)		(l = PopBack(l));
#define		L_GETFRONT(l, v)	(v = GetFront(l));
#define		L_GETBACK(l, v)		(v = GetBack(l));
#define		L_GETIDX(l, i, v)	(v = GetIdx(l, i));
#define		L_GETCOUNT(l, v)	(v = GetCount(l));
#define		L_INSERT(l, v, i)	(l = InsertNode(l, L_CREATE(v), i))
#define		L_REMOVE(l, i)		(l = RemoveNode(l, i))
#define		L_ACTION(l, f)		(ExAction(l, f))

typedef struct	s_list
{
  void*			data;
  struct s_list*	prev;
  struct s_list*	next;
}		t_list;

struct s_list*	CreateNode(void* data);
struct s_list*	PushFront(struct s_list* list, struct s_list* node);
struct s_list*	PushBack(struct s_list* list, struct s_list* node);
struct s_list*	PopFront(struct s_list* list);
struct s_list*	PopBack(struct s_list* list);
void*		GetFront(struct s_list* list);
void*		GetBack(struct s_list* list);
void*		GetIdx(struct s_list* list, unsigned int idx);
unsigned int	GetCount(struct s_list* list);
struct s_list*	InsertNode(struct s_list* list, struct s_list* n, unsigned int idx);
struct s_list*	RemoveNode(struct s_list* list, unsigned int idx);
int		ExAction(struct s_list* list, void (*func)(void*));
void		FreeList(struct s_list* list);
void		FreeListData(struct s_list* list);

#endif		// __TLIST_H__
