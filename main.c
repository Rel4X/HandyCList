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
  L_GETCOUNT(l, c);
  write(1, "-\n", 2);
  printf("%d\n-\n\n", c);
  
  printf("Popfront\n");
  L_POPFRONT(l);
  write(1, "-\n", 2);
  L_ACTION(l, &Print);
  write(1, "-\n\n", 3);

  printf("Getidx: 3\n");
  L_GETIDX(l, 3, a);
  write(1, "-\n", 2);
  printf("V: %s\n-\n\n", a);

  printf("Insert: X->4, Pushback: Z\n");
  L_INSERT(l, "X", 4);
  L_PUSHBACK(l, "Z");
  write(1, "-\n", 2);
  L_ACTION(l, &Print);
  write(1, "-\n\n", 3);

  return (0);
}
