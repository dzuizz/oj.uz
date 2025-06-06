#include "jumps.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int T; scanf("%d",&T);
  for(int k=0;k<T;++k){
  int N, Q;
  assert(2 == scanf("%d %d", &N, &Q));
  std::vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &H[i]));
  }
  init(N, H);

  for (int i = 0; i < Q; ++i) {
    int A, B, C, D;
    assert(4 == scanf("%d %d %d %d", &A, &B, &C, &D));
    int x=minimum_jumps(A,B,C,D),y=brute_force(A,B,C,D);
    if(x!=y){
      printf("%d %d: %d %d\n",k,i,x,y);
      printf(">> %d %d %d %d\n", A,B,C,D);
    }
    //printf("%d %d\n", minimum_jumps(A, B, C, D), brute_force(A,B,C,D));
  }
  }
  return 0;
}
