/** Code jam problem 2 */

#include <stdio.h>
#include <string.h>

int tidy(unsigned long l) {
  unsigned long afterCurrent = l %10;
  unsigned long current;
  int brk = 0;
  l /= 10;
  while (l>1 && !brk){
    current = l %10;
    if (current > afterCurrent) brk = 1;
    afterCurrent = current;
    l/=10;
  }
  current = l %10;
  if (brk || current > afterCurrent) return 0;
  else return 1;
}

unsigned long maketidy(long l) {
  unsigned long afterCurrent = l %10;
  unsigned long current;
  l /= 10;
  int count = 0;
  int brk = 0;
  while (l>1 && !brk){
    current = l %10;
    if (current > afterCurrent) brk = 1;
    afterCurrent = current;
    l/=10;
    count++;
  }
  l = (l*10 + (current - 1) );
  while (count--) l = l*10+9;
  return l;
}

int main() {
  int N = 100;
  unsigned long i,j,k;
  int brk;

  for (i = 0; i < N; i++) {
    printf("Case #%ld: ",i+1);
    scanf("%ld",&k);
    
    brk = 0;
    while (!tidy(k))
      k = maketidy(k);
    
    printf("%ld\n",k);
  }

}
