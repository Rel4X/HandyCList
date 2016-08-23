#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"tlist.h"

void		Print(void* a)
{
  printf("%s\n", (char*)a);
}

int		main()
{
  t_list*	l;
  int		c;
  char*		a;

  L_CREATE(l);

  printf("Pushback: A B C D, Pushfront 0\n");
  L_PUSHBACK(l, "A");
  L_PUSHBACK(l, "B");
  L_PUSHBACK(l, "C");
  L_PUSHBACK(l, "D");
  L_PUSHFRONT(l, "0");
  write(1, "-\n", 2);
  L_ACTION(l, &Print);
  write(1, "-\n\n", 3);

  printf("GetCount\n");
  c = L_GETCOUNT(l);
  write(1, "-\n", 2);
  printf("%d\n-\n\n", c);

  printf("Popfront\n");
  L_POPFRONT(l);
  write(1, "-\n", 2);
  L_ACTION(l, &Print);
  write(1, "-\n\n", 3);

  printf("Getidx: 3\n");
  a = L_GETIDX(l, 3);
  write(1, "-\n", 2);
  printf("V: %s\n-\n\n", a);

  printf("Insert: X->4, Pushback: Z\n");
  L_INSERT(l, "X", 4);
  L_PUSHBACK(l, "Z");
  write(1, "-\n", 2);
  L_ACTION(l, &Print);
  write(1, "-\n\n", 3);

  printf("Boucle While:\n");
  L_ITERATOR	it;

  L_INITIT(l, it);
  while (it)
    {
      printf("%s\n", (char*)L_GETCUR(it));
      I_NEXT(it);
    }
  printf("Boucle For:\n");
  for (L_INITIT(l, it); it; I_NEXT(it))
    {
      printf("%s\n", (char*)L_GETCUR(it));
    }

  return (0);
}
