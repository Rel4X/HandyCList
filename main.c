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

  L_PUSHBACK(l, "A");
  L_PUSHBACK(l, "B");
  L_PUSHBACK(l, "C");
  L_PUSHBACK(l, "D");
  L_PUSHFRONT(l, "0");
  write(1, "-\n", 2);
  L_ACTION(l, &Print);
  write(1, "-\n", 2);

  L_GETCOUNT(l, c);
  printf("%d\n\n", c);
  
  write(1, "-\n", 2);
  L_POPFRONT(l);
  L_ACTION(l, &Print);
  write(1, "-\n", 2);

  write(1, "-\n", 2);
  L_GETIDX(l, 3, a);
  printf("V: %s\n\n", a);

  
  write(1, "-\n", 2);
  L_INSERT(l, "X", 4);
  L_PUSHBACK(l, "Z");
  L_ACTION(l, &Print);
  write(1, "-\n", 2);

  return (0);
}
