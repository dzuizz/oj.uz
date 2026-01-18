#include "grader.h"
#include "cluedo.h"

void Solve(){
  int a[3]={1,1,1},r;
  while(1){
    r=Theory(a[0],a[1],a[2]);
    if(r==0) return;
    ++a[--r];
  }
}
