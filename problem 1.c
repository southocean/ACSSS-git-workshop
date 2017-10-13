/** Code jam problem 1 */

#include <stdio.h>
#include <string.h>

char flip(char c) {
  // commenting
  if (c == '+') return '-';
  else return '+';
}

int main() {

  /* This is a comment */

  int N = 50, i,j,m;
  char s[1500];
  int k, brk, flippingTimes;

  for (i = 0; i < N; i++) {
    scanf(" %1500[-+]s",s); 
    scanf("%d",&k); 
    printf("Case #%d: ",i+1);
    
    brk = flippingTimes = 0;
    if (k > strlen(s)) brk = 1;
    for (j = 0; j < strlen(s) && !brk; j++) {
      if (s[j] == '-') {
        if (j+k <=strlen(s) && ++flippingTimes) for(m = 0; m < k; m++) s[j+m] = flip(s[j+m]);
        else brk = 1;
        //printf("\t%s\n",s);
      }
    }
    if (!brk) printf("%d\n",flippingTimes);
    else printf("IMPOSSIBLE\n");
  }

}
