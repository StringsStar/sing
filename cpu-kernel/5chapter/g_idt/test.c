#include <stdio.h>

int main()
{
  int b=1;
  int c1=2,c2=3;
  __asm__ __volatile__(
	  "add %1, %2\n\t"
	  "movl %2, %%edx\n\t"
	  "movl %%edx, %0\n\t"
	  :"=a"(b)
	  :"b"(c1),"c"(c2)
	  :"%edx"
	  );
  printf("..........%d", b);
  return 0;
}
